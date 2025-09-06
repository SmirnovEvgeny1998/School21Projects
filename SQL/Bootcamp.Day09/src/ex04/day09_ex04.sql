CREATE OR REPLACE FUNCTION fnc_persons_female() RETURNS TABLE(id bigint, name varchar, age integer, gender varchar, address varchar)
    AS $$ SELECT * FROM person WHERE gender = 'female' $$
    LANGUAGE SQL;
CREATE OR REPLACE FUNCTION  fnc_persons_male() RETURNS TABLE(id bigint, name varchar, age integer, gender varchar, address varchar)
    AS $$ SELECT * FROM person WHERE gender = 'male' $$
    LANGUAGE SQL;
SELECT * FROM person WHERE gender = 'female';
SELECT * FROM fnc_persons_female();
SELECT * FROM person WHERE gender = 'male';
SELECT * FROM fnc_persons_male();