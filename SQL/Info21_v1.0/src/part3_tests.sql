/*1*/
SELECT * FROM transfered_points();
/*2*/
SELECT * FROM xp_taken();
/*3*/
SELECT * FROM find_workaholic_peers('2023-11-25');
/*4*/
SELECT * FROM points_change();
/*5*/
SELECT * FROM points_change_from_func_1();
/*6*/
SELECT * FROM most_checked_task();
/*7*/
BEGIN;
call block_finishees('CI');
FETCH ALL IN "finishees";
COMMIT;
/*8*/
SELECT * FROM check_recommendations('burnerwa');
/*9*/
BEGIN;
call work_percents();
FETCH ALL IN "work_percents";
COMMIT;
/*10*/
SELECT * FROM birthday_luck();
/*11*/
BEGIN;
call three_tasks('CI1_SimpleBashUtils', 'CI2_s21_string+', 'CI4_s21_decimal');
FETCH ALL IN "three_tasks";
COMMIT;
/*12*/
select * FROM recrusive_table();
/*13*/
BEGIN;
call show_consecutive_checks(2);
FETCH ALL IN "lucky_day";
COMMIT;
/*14*/
SELECT * FROM da_best();
/*15*/
BEGIN;
call before_time('18:00:00', 1);
FETCH ALL IN "before_time";
COMMIT;
/*16*/
BEGIN;
call gone_how_many_times(0, 232);
FETCH ALL IN "gone_how_many_times";
COMMIT;
/*17*/
SELECT * FROM early_months();