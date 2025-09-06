CREATE OR REPLACE FUNCTION fnc_fibonacci(pstop integer default 10) RETURNS TABLE(fib bigint)
    AS $$ WITH RECURSIVE t(a,b) AS (
            VALUES(0,1)
        UNION ALL
            SELECT greatest(a,b), a + b as a from t
            WHERE b < $1
    )
SELECT a FROM t;
$$ LANGUAGE sql;