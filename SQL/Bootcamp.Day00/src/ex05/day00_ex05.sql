SELECT (
    SELECT name FROM person WHERE p.person_id = id
) AS NAME
FROM person_order p
WHERE (p.menu_id = 13 OR p.menu_id = 14 OR p.menu_id = 18) AND p.order_date = '2022-01-07';