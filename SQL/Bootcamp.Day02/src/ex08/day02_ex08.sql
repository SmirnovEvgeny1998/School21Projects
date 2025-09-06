WITH
per_id AS (SELECT id FROM person WHERE (address = 'Moscow' OR address = 'Samara') AND gender = 'male'),
piz_id AS (SELECT id FROM menu WHERE pizza_name = 'pepperoni pizza' OR pizza_name = 'mushroom pizza')
SELECT person.name FROM person_order
LEFT JOIN person ON person_order.person_id = person.id
WHERE person_order.person_id IN (SELECT id FROM per_id) AND person_order.menu_id IN (SELECT id FROM piz_id)
ORDER BY person.name DESC;