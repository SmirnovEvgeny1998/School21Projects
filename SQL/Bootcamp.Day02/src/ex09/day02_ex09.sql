WITH
per_id AS (SELECT id FROM person WHERE gender = 'female'),
pep_id AS (SELECT id FROM menu WHERE pizza_name = 'pepperoni pizza'),
che_id AS (SELECT id FROM menu WHERE pizza_name = 'cheese pizza')
SELECT person.name FROM person_order
LEFT JOIN person ON person_order.person_id = person.id
WHERE person_order.person_id IN (SELECT id FROM per_id) AND person_order.menu_id IN (SELECT id FROM pep_id)
INTERSECT
SELECT person.name FROM person_order
LEFT JOIN person ON person_order.person_id = person.id
WHERE person_order.person_id IN (SELECT id FROM per_id) AND person_order.menu_id IN (SELECT id FROM che_id)
ORDER BY name;