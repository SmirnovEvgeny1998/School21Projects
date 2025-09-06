-- 1) A stored procedure that, without destroying the database, destroys 
--    all those tables in the current database whose names begin with the phrase 'TableName'.

create or replace procedure remove_tables (TableName varchar) 
language plpgsql
as $$
    declare
        t_row record;
    begin
        for t_row in
                select table_name
                from information_schema.tables
                where table_schema = 'public'
                and table_name like (TableName || '%')
        loop
            execute 'drop table ' || quote_ident(t_row.table_name) || ' cascade';
        end loop;
    end;
$$;

--TESTS:

-- select table_name
-- from information_schema.tables
-- where table_schema = 'public';

-- call remove_tables('t');

-- select table_name
-- from information_schema.tables
-- where table_schema = 'public';


 -- 2) A stored procedure with an output parameter 
 --    that outputs a list of names and parameters 
 --    of all scalar user's SQL functions in the current database. 

create or replace procedure display_scalar_functions(out count_f int)
language plpgsql
as $$
    declare 
        func_row record;
        counter int := 0;
        out_arr text[];
    begin
        for func_row in select concat(proname, proargnames) as func_description
                        from pg_catalog.pg_namespace n
                        join pg_catalog.pg_proc p ON pronamespace = n.oid
                        where p.prokind = 'f'
                        and n.nspname = 'public'
                        -- and language = sql and !arg.Empty() ----------- TO FIX! !!!! !! !  ! ! !
        loop
            out_arr[counter] := func_row.func_description;
            counter := counter + 1;
        end loop;
        raise notice '%', out_arr;
        count_f := counter;
    end;
$$;

-- TESTS
do $$
declare
    num_of_func int := 0;
begin
    call display_scalar_functions(num_of_func);
    raise notice 'Number of scalar functions in database: %', num_of_func;
end;
$$;

-- 3) A stored procedure with output parameter, 
-- which destroys all SQL DML triggers in the current database. 
-- The output parameter returns the number of destroyed triggers.

create or replace procedure destroy_triggers(out destroyed_num int)
language plpgsql
as $$
    declare
        trg_row record;
        trg_counter int := 0;
    begin
        for trg_row in select event_object_table as table_name ,trigger_name         
                                from information_schema.triggers  
                                GROUP BY table_name , trigger_name
        loop
            execute 'drop trigger if exists ' || quote_ident(trg_row.trigger_name) || ' on ' || quote_ident(trg_row.table_name) || ' cascade';
            trg_counter := trg_counter + 1;
        end loop;
        destroyed_num := trg_counter;
    end;
$$;

-- TESTS:

DO $$
DECLARE trg_destroyed int := 0;
BEGIN
  call destroy_triggers(trg_destroyed);
  RAISE NOTICE 'triggers destroyed = %', trg_destroyed;  
END;
$$;

-- -- query for list all DML triggers
-- SELECT  event_object_table AS table_name ,trigger_name         
-- FROM information_schema.triggers  
-- GROUP BY table_name , trigger_name ;


-- 4) A stored procedure with an input parameter that outputs 
--    names and descriptions of object types (only stored procedures 
--    and scalar functions) that have a string specified by the procedure parameter.

create or replace procedure display_objects(string varchar)
language plpgsql
as $$
    declare
        obj_row record;
        counter int := 0;
        out_arr text[];
    begin
    for obj_row in select concat(name, ' (', object_type, ')') as obj 
                    from (select p.proname as name, 'procedure' as object_type, prosrc
                        from pg_catalog.pg_namespace n
                        join pg_catalog.pg_proc p ON p.pronamespace = n.oid
                        where p.prokind = 'p'
                        and n.nspname = 'public'
                        union
                        select p.proname as name, 'function' as object_type, prosrc
                        from pg_catalog.pg_namespace n
                        join pg_catalog.pg_proc p ON p.pronamespace = n.oid
                        where p.prokind = 'f'
                        and n.nspname = 'public')
                    where position(string in prosrc)>0
    loop
        out_arr[counter] := obj_row.obj;
        counter := counter + 1;
    end loop;
    raise notice '%', out_arr;
    end;
$$;

-- TESTS:

DO $$
DECLARE 
    string varchar := 'select';
BEGIN
    call display_objects(string);
END;
$$;

DO $$
DECLARE 
    string varchar := 'join';
BEGIN
    call display_objects(string);
END;
$$;

select *
                        from pg_catalog.pg_namespace n
                        join pg_catalog.pg_proc p ON pronamespace = n.oid
                        where p.prokind = 'f'
                        and n.nspname = 'public';