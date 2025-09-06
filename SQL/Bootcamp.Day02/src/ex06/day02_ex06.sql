SELECT menu.pizza_name ,pizzeria.name AS pizzeria_name FROM person_order
LEFT JOIN menu ON menu.id = person_order.menu_id
LEFT JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
WHERE person_order.person_id IN (SELECT person.id FROM person WHERE person.name = 'Anna' OR person.name = 'Denis')
ORDER BY pizza_name, pizzeria_name;