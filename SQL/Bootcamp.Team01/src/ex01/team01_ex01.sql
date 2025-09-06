WITH past_c AS (SELECT user_id, money, currency_id, updated, MAX(c_updated) AS latest_update
                FROM (SELECT * FROM balance AS b 
                LEFT JOIN LATERAL (SELECT rate_to_usd, updated AS c_updated FROM currency 
                WHERE id = b.currency_id AND updated < b.updated) AS c ON TRUE) AS past
                GROUP BY 1, 2, 3, 4),
future_c AS (SELECT user_id, money, currency_id, updated, MIN(c_updated) AS closest_update
            FROM (SELECT * FROM balance AS b 
            LEFT JOIN LATERAL (SELECT rate_to_usd, updated AS c_updated FROM currency 
            WHERE id = b.currency_id AND updated > b.updated) AS c ON TRUE) AS future
            GROUP BY 1, 2, 3, 4),
actual_update AS (SELECT user_id, money, currency_id, updated,
                        COALESCE(latest_update, closest_update) AS actual_update FROM past_c NATURAL JOIN future_c)

SELECT COALESCE("user".name, 'not defined'),
        COALESCE("user".lastname, 'not defined'),
        currency.name AS currency_name,
        a.money * currency.rate_to_usd AS currency_in_usd
FROM actual_update a
LEFT JOIN "user" ON "user".id = a.user_id
LEFT JOIN currency ON a.currency_id = currency.id AND currency.updated = a.actual_update
WHERE currency.name IS NOT NULL
ORDER BY 1 DESC, 2 ASC, 3 ASC;



