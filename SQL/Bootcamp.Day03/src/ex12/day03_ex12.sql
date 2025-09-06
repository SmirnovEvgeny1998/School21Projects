SELECT * FROM person_order;

WITH m_id AS (SELECT max(id) + 1 AS maxi FROM person_order),
peop_id AS (SELECT id FROM person),
men_id AS (SELECT id FROM menu WHERE pizza_name = 'greek pizza')
insert into person_order (id, person_id, menu_id, order_date)
SELECT n.*, peop_id.id, men_id.id, '2022-02-25'::DATE FROM m_id, men_id, generate_series(m_id.maxi, m_id.maxi + 8, 1) AS n
LEFT JOIN peop_id ON n.* - (SELECT max(id) FROM person_order) = peop_id.id;

SELECT * FROM person_order;