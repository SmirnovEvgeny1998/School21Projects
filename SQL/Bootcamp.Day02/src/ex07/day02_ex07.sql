WITH
low_cost AS (SELECT menu.pizzeria_id FROM menu WHERE menu.price < 800),
per_id AS (SELECT person.id FROM person WHERE person.name = 'Dmitriy')
SELECT pizzeria.name FROM person_visits
LEFT JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
WHERE person_visits.visit_date = '2022-01-08' AND person_visits.person_id IN (SELECT id FROM per_id)
AND pizzeria.id IN (SELECT pizzeria_id FROM low_cost);