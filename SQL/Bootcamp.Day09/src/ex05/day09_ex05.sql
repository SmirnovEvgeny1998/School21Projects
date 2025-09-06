DROP FUNCTION fnc_persons_female;
DROP FUNCTION fnc_persons_male;

CREATE OR REPLACE FUNCTION fnc_persons(pgender in varchar default 'female') RETURNS TABLE(id bigint, name varchar, age integer, gender varchar, address varchar)
    AS $$ SELECT * FROM person WHERE gender = $1 $$
    LANGUAGE SQL;

SELECT * FROM person WHERE gender = 'female';
SELECT * FROM fnc_persons();
SELECT * FROM person WHERE gender = 'male';
SELECT * FROM fnc_persons(pgender := 'male');