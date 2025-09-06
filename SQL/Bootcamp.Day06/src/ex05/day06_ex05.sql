COMMENT ON TABLE person_discounts IS 'The table with discounts for every person in all pizzerias';
COMMENT ON COLUMN person_discounts.id IS 'Unique identificator of table';
COMMENT ON COLUMN person_discounts.person_id IS 'Foreign id from "person" table';
COMMENT ON COLUMN person_discounts.pizzeria_id IS 'Foreign id from "pizzeria" table';
COMMENT ON COLUMN person_discounts.discount IS 'Discount amount in numbers between 0 and 100';

/* Проверка комментариев
select obj_description('public.person_discounts'::regclass);

SELECT
    cols.column_name,
    (
        SELECT
            pg_catalog.col_description(c.oid, cols.ordinal_position::int)
        FROM pg_catalog.pg_class c
        WHERE
            c.oid     = (SELECT cols.table_name::regclass::oid) AND
            c.relname = cols.table_name
    ) as column_comment
 
FROM information_schema.columns cols
WHERE
    cols.table_catalog = 'postgres' AND
    cols.table_schema  = 'public' AND
    cols.table_name    = 'person_discounts'; */