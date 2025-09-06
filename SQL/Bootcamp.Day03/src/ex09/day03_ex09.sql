WITH g_id AS (SELECT id, name FROM pizzeria WHERE name = 'Dominos'),
m_id AS (SELECT max(id) + 1 AS maxi FROM person_visits),
den_id AS (SELECT id FROM person WHERE name = 'Denis')
insert into person_visits (id, person_id, pizzeria_id, visit_date)
SELECT m_id.maxi, den_id.id, g_id.id, '2022-02-24'
FROM g_id, m_id, den_id;

WITH g_id AS (SELECT id, name FROM pizzeria WHERE name = 'Dominos'),
m_id AS (SELECT max(id) + 1 AS maxi FROM person_visits),
iri_id AS (SELECT id FROM person WHERE name = 'Irina')
insert into person_visits (id, person_id, pizzeria_id, visit_date)
SELECT m_id.maxi, iri_id.id, g_id.id, '2022-02-24'
FROM g_id, m_id, iri_id;
SELECT * FROM person_visits;