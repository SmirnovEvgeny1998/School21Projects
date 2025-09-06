SELECT pizzeria.name, count(pizzeria.name) AS count_of_orders, round(AVG(menu.price), 2) AS average_price, max(menu.price) AS max_price, min(menu.price) AS min_price FROM person_order
LEFT JOIN menu ON menu.id = person_order.menu_id
LEFT JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
GROUP BY pizzeria.name
ORDER BY pizzeria.name;
/*readme говорит сократить среднее до 2 чисел после запятой но в примере целые числа. Тут оставлю как просят, чтобы было целое просто нужно убрать round.*/