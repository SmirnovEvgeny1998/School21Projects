WITH vis AS (
    SELECT pizzeria.name, count(pizzeria.name), 'visit' AS action_type FROM person_visits
    LEFT JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
    GROUP BY pizzeria.name),
ord AS (
    SELECT pizzeria.name, count(pizzeria.name), 'order' AS action_type FROM person_order
    LEFT JOIN menu ON menu.id = person_order.menu_id
    LEFT JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
    GROUP BY pizzeria.name)
SELECT vis.name, 
(CASE WHEN vis.count IS NOT NULL AND ord.count IS NOT NULL THEN (vis.count + ord.count)
WHEN vis.count IS NOT NULL THEN vis.count
WHEN ord.count IS NOT NULL THEN ord.count
ELSE 0 END) AS total_count FROM vis
LEFT JOIN ord ON vis.name = ord.name
ORDER BY total_count DESC, vis.name ASC;