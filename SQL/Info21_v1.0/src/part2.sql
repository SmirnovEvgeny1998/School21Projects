-- 1) Write a procedure for adding P2P check

create or replace procedure add_P2P_check(CheckingPeer varchar, CheckerPeer varchar, TaskName varchar, stat v$Check, Time1 time)
language plpgsql
as $$
    begin
        if stat = 'Start' then 
            with new_check AS (
                insert into Checks (ID, Peer, Task, Date) values (DEFAULT, CheckingPeer, TaskName, current_date)
                returning *
            )
            insert into P2P values (DEFAULT, (select ID from new_check), CheckerPeer, stat, Time1);
        else
            insert into P2P values (DEFAULT, 
                                    (select max(ID) 
                                    from Checks 
                                    where Peer = CheckingPeer 
                                    and Task = TaskName and Date = current_date),
                                    CheckerPeer, 
                                    stat, 
                                    Time1);
        end if;
    end;
$$;


-- 2) Write a procedure for adding checking by Verter:

create or replace procedure add_Verter_check (CheckingPeer varchar, TaskName name, stat v$Check , vTime time) 
language plpgsql
as $$
    begin
        with verified_checks as (select ch.ID, p.Time from Checks ch
                                full join p2p p on p.v$check = ch.ID 
                                where ch.Peer = p.CheckingPeer and ch.Task = TaskName
                                and p.State = 'Success')
        insert into Verter values (DEFAULT, 
                                (select ID from verified_checks 
                                where time = (select max(time) from verified_checks)),
                                stat, 
                                vTime);                         
    end;
$$;


-- 3) Write a trigger: after adding a record with the "start" status to the P2P table, change the corresponding record in the TransferredPoints table

create or replace function change_TransferredPoints() returns trigger as $trg_P2P_insert$
    begin
        update TransferredPoints
        set PointsAmount = PointsAmount + 1
        where CheckingPeer = new.CheckingPeer
        and CheckedPeer = (select Peer from Checks where ID = new.v$Check);
        return null;
    end;
$trg_P2P_insert$ language plpgsql;

create or replace trigger trg_P2P_insert
    after insert on P2P
    for each row
    when (new.State = 'Start')
    execute function change_TransferredPoints();


-- 4) Write a trigger: before adding a record to the XP table, check if it is correct

create or replace function XP_insert_check() returns trigger as $trg_XP_insert$ 
    begin
        if (new.XPAmount > (select MaxXP from Tasks where Title = (select Task from Checks where new.v$Check))) then
            raise exception '% is greater than maximum XP for this task', new.XPAmount;
            return null;
        end if;
        if (new.v$Check not in (select P2P.v$Check from P2P
                                where P2P.v$Check = new.v$Check
                                and State = 'Success')) then
            raise exception '% is ID of non-successfull check', new.v$Check;
            return null;
        end if;
        return new;
    end;
$trg_XP_insert$ language plpgsql;

create or replace trigger trg_xp_insert
    before insert on XP 
    for each row 
    execute function XP_insert_check();

