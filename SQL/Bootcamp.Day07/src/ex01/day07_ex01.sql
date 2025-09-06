SELECT person.name, count(person.name) AS count_of_visits FROM person_visits
LEFT JOIN person ON person.id = person_visits.person_id
GROUP BY person.name, person_visits.person_id
ORDER BY count_of_visits DESC, person.name
LIMIT 4;