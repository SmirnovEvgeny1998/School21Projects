WITH kat_id AS (SELECT id FROM person WHERE name = 'Kate'),
pr_id AS (SELECT id FROM menu WHERE price BETWEEN 800 AND 1000)
SELECT menu.pizza_name, menu.price, pizzeria.name AS pizzeria_name, visit_date FROM person_visits
LEFT JOIN menu ON menu.pizzeria_id = person_visits.pizzeria_id 
LEFT JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
WHERE person_visits.person_id IN (SELECT id FROM kat_id) AND menu.id IN (SELECT id FROM pr_id)
ORDER BY pizza_name, price, pizzeria_name;