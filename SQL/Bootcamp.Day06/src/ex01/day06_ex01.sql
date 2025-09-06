WITH cou AS (
    SELECT person_id, pizzeria_id, count(person_id) AS discount FROM person_order
    LEFT JOIN menu ON menu.id = person_order.menu_id
    LEFT JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
    LEFT JOIN person ON person.id = person_order.person_id
    GROUP BY person_id, pizzeria_id
)
INSERT INTO person_discounts (id, person_id, pizzeria_id, discount)
    SELECT (ROW_NUMBER () OVER (ORDER BY person_id)) AS id,
    cou.person_id, cou.pizzeria_id,
    CASE WHEN cou.discount = 1 THEN 10.5::numeric
    WHEN cou.discount = 2 THEN 22::numeric
    ELSE 30::numeric
    END discount
    FROM cou;
SELECT * FROM person_discounts;