SELECT order_date, (person.name || ' (age:' || person.age || ')') AS person_information FROM person_order 
NATURAL JOIN (SELECT name, age, id AS person_id FROM person) AS person
ORDER BY order_date ASC, person_information ASC;