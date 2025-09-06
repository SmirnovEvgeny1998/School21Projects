CREATE unique INDEX idx_person_discounts_unique ON person_discounts(person_id, pizzeria_id);
SET enable_seqscan TO off;
EXPLAIN ANALYZE SELECT person_id, pizzeria_id FROM person_discounts;
SET enable_seqscan TO on;