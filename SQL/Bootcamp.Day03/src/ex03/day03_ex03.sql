WITH a_p AS (
    SELECT count(gender) AS x, pizzeria.name FROM person_visits
    LEFT JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
    LEFT JOIN person ON person.id = person_visits.person_id
    WHERE gender = 'male'
    GROUP BY pizzeria.name),
w_p AS (
    SELECT count(gender) AS x, pizzeria.name FROM person_visits
    LEFT JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
    LEFT JOIN person ON person.id = person_visits.person_id
    WHERE gender = 'female'
    GROUP BY pizzeria.name)
SELECT a_p.name AS pizzeria_name FROM a_p
LEFT JOIN w_p ON w_p.name = a_p.name
WHERE a_p.name = w_p.name AND (w_p.x > a_p.x OR w_p.x < a_p.x);