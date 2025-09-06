CREATE INDEX idx_person_name ON person ((upper(name)));
SET enable_seqscan TO off;
EXPLAIN ANALYZE SELECT * FROM person WHERE upper(name) = 'Dmitriy';
SET enable_seqscan TO on;