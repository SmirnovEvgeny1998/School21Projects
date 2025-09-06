CREATE TABLE IF NOT EXISTS person_audit
(   created TIMESTAMP WITH TIME ZONE not null,
    type_event CHAR(1) not null,
    row_id bigint not null,
    name varchar,
    age integer,
    gender varchar,
    address varchar
);
ALTER TABLE person_audit
ADD constraint ch_nn_created CHECK (created IS NOT NULL),
ALTER COLUMN created SET default now(),
ADD constraint ch_type_event CHECK (type_event = 'I' OR type_event = 'D' OR type_event = 'U'),
ADD constraint ch_nn_type_event CHECK (type_event IS NOT NULL),
ALTER COLUMN type_event SET default 'I',
ADD constraint ch_nn_row_id CHECK (row_id IS NOT NULL);

CREATE FUNCTION fnc_trg_person_insert_audit() RETURNS TRIGGER AS $trg_person_insert_audit$
    BEGIN
        IF (TG_OP = 'INSERT') THEN
            INSERT INTO person_audit SELECT now(), 'I', NEW.id, NEW.name, NEW.age, NEW.gender, NEW.address;
        END IF;
        RETURN NULL;
    END;
$trg_person_insert_audit$ LANGUAGE plpgsql;

CREATE TRIGGER trg_person_insert_audit
AFTER INSERT ON person
    FOR EACH ROW EXECUTE FUNCTION fnc_trg_person_insert_audit();

INSERT INTO person(id, name, age, gender, address) VALUES (10,'Damir', 22, 'male', 'Irkutsk');
SELECT * FROM person_audit;