WITH currency_a AS ( 
    SELECT id, max(updated) AS updated, name
    FROM currency
    GROUP BY id, name)
SELECT COALESCE("user".name, 'not defined'), 
        COALESCE("user".lastname, 'not defined'), balance.type, sum(balance.money) AS volume, 
        COALESCE(currency_a.name, 'not defined') AS currency_name,
        COALESCE(currency.rate_to_usd,1::numeric) AS last_rate_to_usd,
        sum(balance.money * COALESCE(currency.rate_to_usd,1::numeric)) AS total_volume_in_usd
FROM "user"
RIGHT JOIN balance ON "user".id = balance.user_id
LEFT JOIN currency_a ON currency_a.id = balance.currency_id
LEFT JOIN currency ON currency.updated = currency_a.updated AND currency.id = currency_a.id
GROUP BY "user".name, "user".lastname, balance.type, currency_name, rate_to_usd
ORDER BY 1 DESC, 2 ASC, 3 ASC;