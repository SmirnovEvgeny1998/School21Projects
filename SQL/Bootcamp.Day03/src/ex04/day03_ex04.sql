WITH f_p AS (SELECT pizzeria.name FROM person_order
LEFT JOIN menu ON person_order.menu_id = menu.id
LEFT JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
LEFT JOIN person ON person.id = person_order.person_id
WHERE person.gender = 'female'
GROUP BY pizzeria.name
ORDER BY pizzeria.name),
m_p AS (SELECT pizzeria.name FROM person_order
LEFT JOIN menu ON person_order.menu_id = menu.id
LEFT JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
LEFT JOIN person ON person.id = person_order.person_id
WHERE person.gender = 'male'
GROUP BY pizzeria.name
ORDER BY pizzeria.name)
SELECT name AS pizzeria_name FROM f_p
EXCEPT
SELECT name AS pizzeria_name FROM m_p;