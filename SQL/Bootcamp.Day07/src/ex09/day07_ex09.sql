SELECT person.address, 
    round((max(person.age)::numeric - (min(person.age)::numeric / max(person.age)::numeric))::numeric, 2) AS formula, 
    round(avg(person.age), 2) AS average, 
    (max(person.age) - (min(person.age) / max(person.age))) > avg(person.age) AS comparison
FROM person
GROUP BY address
ORDER BY address; 