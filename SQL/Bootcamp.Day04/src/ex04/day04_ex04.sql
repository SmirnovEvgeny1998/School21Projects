CREATE VIEW v_symmetric_union AS
    WITH o_ex AS (
        SELECT person_id FROM person_visits WHERE visit_date = '2022-01-02'
        EXCEPT SELECT person_id FROM person_visits WHERE visit_date = '2022-01-06'),
        t_ex AS (
        SELECT person_id FROM person_visits WHERE visit_date = '2022-01-06'
        EXCEPT SELECT person_id FROM person_visits WHERE visit_date = '2022-01-02')
    SELECT o_ex.person_id FROM o_ex
    UNION
    SELECT t_ex.person_id FROM t_ex
    ORDER BY person_id;
SELECT * FROM v_symmetric_union;