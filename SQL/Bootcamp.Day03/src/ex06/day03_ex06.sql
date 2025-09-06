WITH a_p AS (
    SELECT menu.pizza_name, menu.price, pizzeria.name FROM menu
    LEFT JOIN pizzeria ON menu.pizzeria_id = pizzeria.id),
a_p2 AS (
    SELECT menu.pizza_name, menu.price, pizzeria.name FROM menu
    LEFT JOIN pizzeria ON menu.pizzeria_id = pizzeria.id)
SELECT a_p.pizza_name, a_p.name AS pizzeria_name_1, a_p2.name AS pizzeria_name_2, a_p.price FROM a_p
LEFT JOIN a_p2 ON a_p.pizza_name = a_p2.pizza_name AND a_p.price = a_p2.price
WHERE a_p.name < a_p2.name
ORDER BY a_p2.pizza_name;