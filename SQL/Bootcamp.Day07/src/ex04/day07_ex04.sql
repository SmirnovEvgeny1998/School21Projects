WITH cou AS (
    SELECT person.name, count(person.name) AS count_of_visits FROM person_visits
    LEFT JOIN person ON person.id = person_visits.person_id
    GROUP BY person.name)
SELECT * FROM cou
WHERE cou.count_of_visits > 3;