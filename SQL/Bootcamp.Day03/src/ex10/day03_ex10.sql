WITH m_id AS (SELECT max(id) + 1 AS maxi FROM person_order),
den_id AS (SELECT id FROM person WHERE name = 'Denis'),
men_id AS (SELECT id FROM menu WHERE pizza_name = 'sicilian pizza')
insert into person_order (id, person_id, menu_id, order_date)
SELECT m_id.maxi, den_id.id, men_id.id, '2022-02-24'
FROM men_id, m_id, den_id;

WITH m_id AS (SELECT max(id) + 1 AS maxi FROM person_order),
iri_id AS (SELECT id FROM person WHERE name = 'Irina'),
men_id AS (SELECT id FROM menu WHERE pizza_name = 'sicilian pizza')
insert into person_order (id, person_id, menu_id, order_date)
SELECT m_id.maxi, iri_id.id, men_id.id, '2022-02-24'
FROM men_id, m_id, iri_id;

SELECT * FROM person_order;