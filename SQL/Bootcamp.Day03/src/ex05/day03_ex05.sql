WITH a_v AS (
    SELECT pizzeria.name FROM person_visits
    LEFT JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
    LEFT JOIN person ON person.id = person_visits.person_id
    WHERE person.name = 'Andrey'
    GROUP BY pizzeria.name
),
a_o AS (
    SELECT pizzeria.name FROM person_order
    LEFT JOIN menu ON person_order.menu_id = menu.id
    LEFT JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
    LEFT JOIN person ON person.id = person_order.person_id
    WHERE person.name = 'Andrey'
    GROUP BY pizzeria.name
)
SELECT name AS pizzeria_name FROM a_v
EXCEPT
SELECT name FROM a_o
ORDER BY pizzeria_name;