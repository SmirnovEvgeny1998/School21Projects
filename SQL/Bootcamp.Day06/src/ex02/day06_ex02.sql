SELECT person.name, menu.pizza_name, menu.price, (menu.price / 100 * (100 - person_discounts.discount))::integer AS discount_price, pizzeria.name AS pizzeria_name FROM menu
LEFT JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
LEFT JOIN person_discounts ON person_discounts.pizzeria_id = pizzeria.id
LEFT JOIN person ON person.id = person_discounts.person_id
ORDER BY person.name, menu.pizza_name;