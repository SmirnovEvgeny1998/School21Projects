WITH vis AS (
    SELECT pizzeria.name, count(pizzeria.name), 'visit' AS action_type FROM person_visits
    LEFT JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
    GROUP BY pizzeria.name
    ORDER BY count DESC
    LIMIT 3),
ord AS (
    SELECT pizzeria.name, count(pizzeria.name), 'order' AS action_type FROM person_order
    LEFT JOIN menu ON menu.id = person_order.menu_id
    LEFT JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
    GROUP BY pizzeria.name
    ORDER BY count DESC
    LIMIT 3)
SELECT * FROM vis
UNION
SELECT * FROM ord
ORDER BY action_type ASC, count DESC;