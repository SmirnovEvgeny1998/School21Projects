WITH m AS(SELECT generate_series('2022-01-01'::date, '2022-01-10'::date, interval '1 day') AS missing_date)
SELECT missing_date::DATE FROM m
LEFT JOIN person_visits ON missing_date = visit_date AND (person_id = 1 OR person_id = 2)
WHERE visit_date IS NULL
ORDER BY missing_date;