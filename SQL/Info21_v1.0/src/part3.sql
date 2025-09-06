/*1*/
create or replace function transfered_points()
returns table (
		Peer1 varchar,
		Peer2 varchar,
        PointsAmount bigint
	)
language plpgsql
as
$$
begin

    return query 
        with origin as (
            SELECT CheckingPeer, CheckedPeer, TransferredPoints.PointsAmount FROM TransferredPoints
        )
        select
            o1.CheckingPeer,
            o1.CheckedPeer, 
            case when o2.PointsAmount is NULL then o1.PointsAmount - 0
            else o1.PointsAmount - o2.PointsAmount 
            end Amount
        from
            origin o1
        left join
            origin o2
        on
            o1.CheckingPeer = o2.CheckedPeer and o1.CheckedPeer = o2.CheckingPeer
        group by 
            o1.CheckingPeer, o1.CheckedPeer, o1.PointsAmount, o2.PointsAmount;
    

end;
$$;


/*2*/
create or replace function xp_taken()
returns table (
		Peer varchar,
		Task varchar,
        XP bigint
	)
language plpgsql
as
$$
begin

    return query 
        select
            Checks.Peer,
            Checks.Task,
            XP.XPAmount
        from
            XP
        left join 
            Checks
        on
            XP.v$Check = Checks.ID;

end;
$$;


/*3*/
create or replace function find_workaholic_peers(dates date)
returns table (
		Workaholic varchar
	)
language plpgsql
as
$$
begin

    return query 
        with coming_peers as (
            select Peer from TimeTracking where Date = dates and State = 1
        ), returning_peers as (
            select Peer from TimeTracking where Date = dates and State = 2
        )
        select * from coming_peers
        except 
        select * from returning_peers;

end;
$$;


/*4*/
create or replace function points_change()
returns table (
		Peer varchar,
        PointsChange numeric
	)
language plpgsql
as
$$
begin

    return query 
        with profit as (
        select CheckingPeer, sum(PointsAmount) as plus from TransferredPoints group by CheckingPeer
        ), deficit as (
            select CheckedPeer, sum(PointsAmount) as minus from TransferredPoints group by CheckedPeer
        )
        select
            case when profit.CheckingPeer is NULL then deficit.CheckedPeer
            else profit.CheckingPeer
            end Peers
            , 
            case when deficit.minus is NULL then profit.plus - 0
            when profit.plus is NULL then 0 - deficit.minus
            else profit.plus - deficit.minus 
            end Amount
        from
            profit
        full join
            deficit
        on
            profit.CheckingPeer = deficit.CheckedPeer
        order by
            Amount DESC;

end;
$$;


/*5*/
create or replace function points_change_from_func_1()
returns table (
		Peer varchar,
        PointsChange bigint
	)
language plpgsql
as
$$
begin

    return query 
        with unredacted as (
            select Peer1, Peer2, sum(PointsAmount) as income from transfered_points() group by Peer1, Peer2
        ), redacted as (
            select p1.Peer1, p1.Peer2, p1.income from unredacted p1
            join
        unredacted p2 on p1.Peer1 = p2.Peer2 and p2.Peer1 = p1.Peer2 WHERE p1.Peer1 > p1.Peer2
        ), cleaned as (
            select * from unredacted except select * from redacted
        ), profit as (
            select Peer1, sum(income) as plus from cleaned group by Peer1
        ), deficit as (
            select Peer2, sum(income) as minus from cleaned group by Peer2
        )
        select case when profit.Peer1::varchar is NULL then deficit.Peer2::varchar
                else profit.Peer1::varchar
                end Peers
            , 
            case when deficit.minus::bigint is NULL then profit.plus::bigint - 0
                when profit.plus::bigint is NULL then 0 - deficit.minus::bigint
                else profit.plus::bigint - deficit.minus::bigint
                end Amount
            from
                profit
            full join
                deficit
            on
                profit.Peer1 = deficit.Peer2
            order by
                Amount DESC;


end;
$$;


/*6*/
create or replace function most_checked_task()
returns table (
		Day date,
        Task varchar
	)
language plpgsql
as
$$
begin

    return query 
        with unredacted as (
            select Checks.Date, Checks.Task, count(Checks.Date) as numbers from Checks group by Checks.Date, Checks.Task
        ), redacted as (
            select Date, max(numbers) as maxnumbers from unredacted GROUP BY Date
        ), joined as (
            select redacted.Date, unredacted.Task from redacted
            inner join unredacted on redacted.Date = unredacted.Date and redacted.maxnumbers = unredacted.numbers
        ), agged as (
            SELECT joined.Date, STRING_AGG(joined.Task, ',') as allmax FROM joined GROUP BY Date
        )
        SELECT Date, allmax::varchar FROM agged order BY Date;
end;
$$;


/*7*/
create or replace procedure block_finishees(block varchar)
language plpgsql
as
$$
declare
   formated varchar;
   ref refcursor := 'finishees';  
begin
    OPEN ref FOR 
        with lasttask as (
        SELECT * FROM Tasks where Title ~ ('\m' || block) order by Title desc limit 1
        )
        select Checks.Peer, Checks.Date as Day from lasttask
        left join Checks on lasttask.Title = Checks.Task;
end;
$$;


/*8*/
create or replace function check_recommendations(nickname varchar)
returns table (
		Peer varchar,
        RecommendedPeer varchar
	)
language plpgsql
as
$$
declare
   formated varchar;
begin
    return query 
        with friendslist as (
            SELECT * FROM Friends WHERE Peer1 = nickname or Peer2 = nickname
        ), recomendators as (
            SELECT  case when Peer1 = nickname then Peer2
                    else Peer1
                    end recs
            from friendslist
        )
        SELECT recomendators.recs, Recommendations.RecommendedPeer from recomendators
        LEFT JOIN Recommendations on recomendators.recs = Recommendations.Peer;
end;
$$;


/*9*/
create or replace procedure work_percents()
language plpgsql
as
$$
declare
   formated varchar;
   ref refcursor := 'work_percents';  
begin
    OPEN ref FOR 
        WITH nondoners as (
            SELECT Nickname FROM Peers
            except select Peer from Checks
        ), b1doners as (
            select distinct Checks.Peer from Checks
            left join Peers on Checks.Peer = Peers.Nickname
            where Checks.Task ~ ('\mCI')
        ), b2doners as (
            select distinct Checks.Peer from Checks
            left join Peers on Checks.Peer = Peers.Nickname
            where Checks.Task ~ ('\mSQL')
        ), alldoners as (
            select b1doners.Peer from b1doners
            intersect
            select b2doners.Peer from b2doners
        ), pall as (
            select count(Peers.Nickname) as num from Peers
        ), p0 as (
            select count(nondoners.Nickname) as num from nondoners
        ), peers1 as (
            select b1doners.Peer from b1doners
            except select alldoners.Peer from alldoners
        ), peers2 as (
            select b2doners.Peer from b2doners
            except select alldoners.Peer from alldoners
        ), p1 as (
            select count(*) as num from peers1
        ), p2 as (
            select count(*) as num from peers2
        ), p3 as (
            select count(*) as num from alldoners
        )
        select 
            p1.num::numeric / pall.num::numeric * 100 as StartedBlock1,
            p2.num::numeric / pall.num::numeric * 100 as StartedBlock2,
            p3.num::numeric / pall.num::numeric * 100 as StartedBothBlocks,
            p0.num::numeric / pall.num::numeric * 100 as DidntStartAnyBlock

        from p0, p1, p2, p3, pall;
end;
$$;


/*10*/
create or replace function birthday_luck()
returns table (
		SuccessfulChecks numeric,
    UnsuccessfulChecks numeric
	)
language plpgsql
as
$$
begin
    return query 
      with char_checks as (
        select ID, Peer, Task, to_char(Date, 'MM-DD') as md from Checks
      ), char_peers as (
        select Nickname, to_char(Birthday, 'MM-DD') as md from Peers
      ), inters as (
        select char_peers.Nickname, char_peers.md, char_checks.Task, char_checks.ID from char_peers
        left join char_checks on char_peers.Nickname = char_checks.Peer and char_peers.md = char_checks.md
        where char_checks.Task is not null
      ), successes as (
        select count(*) as cou from inters
        left join Verter on inters.ID = Verter.v$Check
        where Verter.State = 'Success'
      ), alls as (
        select count(*) as cou from inters
      )
      select successes.cou::numeric / alls.cou::numeric * 100,
      (alls.cou::numeric - successes.cou::numeric) / alls.cou::numeric * 100
      from successes, alls;
end;
$$;


/*11*/
create or replace procedure three_tasks(t1 varchar, t2 varchar, t3 varchar)
language plpgsql
as
$$
declare
   formated varchar;
   ref refcursor := 'three_tasks'; 
begin
    OPEN ref FOR  
        with firstpeers as (
            SELECT Peer from Checks where Task = t1
        ), secondpeers as (
            SELECT Peer from Checks where Task = t2
        ), thirdpeer as (
            SELECT Peer from Checks where Task = t3
        ), boths as (
            SELECT Peer from firstpeers
            intersect select Peer from secondpeers
        ), exclude as (
            SELECT Peer from boths
            except select Peer from thirdpeer
        )
        select Peer from exclude;
end;
$$;


/*12*/
create or replace function recrusive_count(taskname varchar)
returns table (
		PrevCount bigint
	)
language plpgsql
as
$$
begin
    return query 
      WITH RECURSIVE r AS (
         SELECT Title, ParentTask
         FROM Tasks
         where Title = taskname
      
         UNION
      
         SELECT r.ParentTask as Title, (SELECT ParentTask FROM Tasks where r.ParentTask = Tasks.Title) as ParentTask
         FROM r
         where r.ParentTask is not null
      ), cou as (
        SELECT count(*) - 1 as amount FROM r
      )
      
      SELECT * FROM cou;
end;
$$;
/*12*/
create or replace function recrusive_table()
returns table (
		Task varchar,
		PrevCount bigint
	)
language plpgsql
as
$$
begin
    return query 
      SELECT Title, recrusive_count(Title) FROM Tasks;
end;
$$;


/*13*/
create or replace function lucky_day_check(day Date, consec bigint, startfrom bigint)
returns varchar
language plpgsql
as
$$
declare
   response varchar;
begin
    with p2p_join as (
      select Checks.*, P2P.Time, P2P.State as f_check, Verter.State as s_check from Checks
      left join P2P on P2P.v$Check = Checks.ID
      left join Verter on Verter.v$Check = Checks.ID
      where (P2P.State = 'Success' or P2P.State = 'Failure') 
      and (Verter.State is null or Verter.State = 'Success' or Verter.State = 'Failure')
      and Checks.Date = day
    ), p2p_start as (
      select p2p_join.*, P2P.Time as begin_time from p2p_join
      left join P2P on P2P.v$Check = p2p_join.ID
      where P2P.State = 'Start'
      order by p2p_join.Date, P2P.Time
    ), all_successes as (
      select p2p_start.* from p2p_start
      left join XP on XP.v$Check = p2p_start.ID
      left join Tasks on Tasks.Title = p2p_start.Task
      where p2p_start.f_check = 'Success' and p2p_start.s_check = 'Success' 
      and XP.XPAmount::numeric / Tasks.MaxXP::numeric >= 0.8
    ), limited as (
      select * from p2p_start
      limit consec offset startfrom
    ), intersection as (
      select * from limited
      intersect select * from all_successes
    ), counter as (
      select count(*) as cou from intersection
    )
    select 
    case when cou = consec then 'Yes'
    else 'No'
    end sss
    into response from counter;
    
    return response;

end;
$$;
/*13*/
create or replace function recrusive_lucky_day(day Date, consec bigint, cou bigint)
returns varchar
language plpgsql
as
$$
declare
  result varchar;
begin
    with RECURSIVE r AS (
      select 0 as i, lucky_day_check(day, consec, 0) as islucky
      
      union
      
      select i+1 as i, lucky_day_check(day, consec, i) as islucky
      from r
      where consec + i < cou
    )
    select distinct islucky into result from r where islucky = 'Yes';
    
    return result;

end;
$$;
/*13*/
create or replace procedure show_consecutive_checks(consec bigint)
language plpgsql
as
$$
declare
  ref refcursor := 'lucky_day';  
begin
  OPEN ref FOR 
    with t as (
      select Date, count(Date) as cou from Checks group by Date
    ), selected as (
      select distinct
      case when recrusive_lucky_day(Checks.Date, consec, (select cou from t where t.Date = Checks.Date)) = 'Yes' then Checks.Date
      else '1000-01-01'
      end lucky_day
      from Checks, t
    )
      select selected.* from selected where lucky_day != '1000-01-01';

end;
$$;


/*14*/
create or replace function da_best()
returns table (
		Peer varchar,
		XP numeric
	)
language plpgsql
as
$$
begin
    return query 
      select Checks.Peer, sum(XP.XPAmount) as XPGot from Checks
      left join XP on XP.v$Check = Checks.ID
      where XP.XPAmount is not null
      group by Checks.Peer
      order by XPGot desc
      limit 1;
end;
$$;


/*15*/
create or replace procedure before_time(given_time time, amount bigint)
language plpgsql
as
$$
declare
   ref refcursor := 'before_time'; 
begin
    OPEN ref FOR 
      with p as (
        select TimeTracking.Peer, count(TimeTracking.Peer) as cou from TimeTracking
        where TimeTracking.Time < given_time and State = 1
        group by TimeTracking.Peer
      )
      SELECT p.Peer FROM p where p.cou >= amount;

end;
$$;


/*16*/
create or replace procedure gone_how_many_times(days bigint, amount bigint)
language plpgsql
as
$$
declare
  ref refcursor := 'gone_how_many_times';  
begin
    OPEN ref FOR  
      with a as (
        SELECT distinct TimeTracking.Peer, count(TimeTracking.Peer) as cou from TimeTracking
        where State = 2 and Date >= (now()::date - interval '1 day' * days)
        group by TimeTracking.Peer
      )
      SELECT a.Peer from a where cou > amount;

end;
$$;


/*17*/
create or replace function early_months()
returns table (
		Month text,
		EarlyEntries bigint
	)
language plpgsql
as
$$
begin
    return query 
      with recursive months as (
        SELECT 1 as i
        
        union
        
        SELECT i+1 FROM months
        where i < 12
      ), peer_month as (
        SELECT Nickname, (SELECT EXTRACT(MONTH FROM Birthday)) as b_month FROM Peers
      ), campus_month as (
        SELECT Peer, (SELECT EXTRACT(MONTH FROM date)) as c_month, Time FROM TimeTracking where State = 1
      ), months_cou as (
        SELECT campus_month.c_month, count(campus_month.c_month) as cou FROM campus_month
        left join peer_month on peer_month.Nickname = campus_month.Peer and peer_month.b_month = campus_month.c_month
        where peer_month.Nickname is not null
        group by campus_month.c_month
      ), early as (
          SELECT campus_month.c_month, count(campus_month.c_month) as cou FROM campus_month
          left join peer_month on peer_month.Nickname = campus_month.Peer and peer_month.b_month = campus_month.c_month
          where peer_month.Nickname is not null and Time < '12:00:00'
          group by campus_month.c_month
      )
      SELECT to_char(to_timestamp (i::text, 'MM'), 'TMmonth') as gg, 
      case when months_cou.cou is null then 0
      else (coalesce(early.cou, 0)::numeric / coalesce(months_cou.cou, 0)::numeric * 100)::bigint
      end EarlyEntries
      FROM months
      left join months_cou on months.i = months_cou.c_month
      left join early on early.c_month = months.i;

end;
$$;