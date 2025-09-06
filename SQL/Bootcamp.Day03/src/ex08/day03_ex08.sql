WITH g_id AS (SELECT id, name FROM pizzeria),
m_id AS (SELECT max(id) + 1 AS maxi FROM menu)
insert into menu (id, pizzeria_id, pizza_name, price)
SELECT m_id.maxi, g_id.id, 'sicilian pizza', 900
FROM g_id, m_id
WHERE g_id.name = 'Dominos';
SELECT * FROM menu;