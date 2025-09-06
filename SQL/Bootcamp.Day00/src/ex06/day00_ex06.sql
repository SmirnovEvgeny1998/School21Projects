SELECT (
    SELECT name FROM person WHERE p.person_id = id
) AS NAME, case when a.name = 'Denis' then 'TRUE' else 'FALSE' end as check_name
FROM person_order p, person a
WHERE (p.menu_id = 13 OR p.menu_id = 14 OR p.menu_id = 18) AND p.order_date = '2022-01-07' AND p.person_id = a.id;