CREATE FUNCTION fnc_person_visits_and_eats_on_date(pperson in varchar default 'Dmitriy', pprice in numeric default 500, pdate in DATE default '2022-01-08') 
    RETURNS TABLE (pizzeria_name varchar)
    LANGUAGE plpgsql
as $$
BEGIN
    RETURN query
        SELECT DISTINCT pizzeria.name FROM person_visits
        LEFT JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id 
        LEFT JOIN menu ON pizzeria.id = menu.pizzeria_id
        LEFT JOIN person ON person.id = person_visits.person_id
        WHERE menu.price < $2 AND person.name = $1 AND person_visits.visit_date = $3;
END;$$