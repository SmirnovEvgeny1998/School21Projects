WITH non_id AS (SELECT menu_id FROM person_order)
SELECT menu.id AS menu_id FROM menu
LEFT JOIN person_order ON person_order.menu_id = menu.id
WHERE menu.id NOT IN (SELECT menu_id FROM non_id)
ORDER BY menu.id;