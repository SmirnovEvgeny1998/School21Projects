With m_id AS (SELECT max(id) + 1 AS id FROM person_visits),
d_id AS (SELECT id AS person_id FROM person WHERE name = 'Dmitriy'),
lp_id AS (
    SELECT pizzeria_id FROM menu
    LEFT JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
    WHERE pizzeria.name != 'Papa Johns' AND menu.price < 800
    LIMIT 1)
insert into person_visits (id, person_id, pizzeria_id, visit_date)
SELECT m_id.id, d_id.person_id, lp_id.pizzeria_id, '2022-01-08'::DATE
FROM m_id, d_id, lp_id;
REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;
SELECT * FROM mv_dmitriy_visits_and_eats;