CREATE SEQUENCE seq_person_discounts;
SELECT setval('seq_person_discounts', (SELECT count(*) FROM person_discounts));
ALTER TABLE person_discounts
ALTER COLUMN id SET default nextval('seq_person_discounts');