WITH non_id AS (SELECT menu_id FROM person_order)
SELECT menu.pizza_name, menu.price, pizzeria.name AS pizzeria_name FROM menu
LEFT JOIN person_order ON person_order.menu_id = menu.id
LEFT JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
WHERE menu.id NOT IN (SELECT menu_id FROM non_id)
ORDER BY pizza_name, price;