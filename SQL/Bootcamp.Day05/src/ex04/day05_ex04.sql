CREATE UNIQUE INDEX idx_menu_unique
ON menu(pizzeria_id, pizza_name);
SET enable_seqscan TO off;
EXPLAIN ANALYZE SELECT pizzeria_id, pizza_name
FROM menu
WHERE pizzeria_id = 4 AND pizza_name = 'cheese pizza';
SET enable_seqscan TO on;