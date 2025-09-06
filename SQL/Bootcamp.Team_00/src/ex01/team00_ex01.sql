WITH RECURSIVE r(a,b,c) AS (
    VALUES('A', 0::numeric, '{A')
UNION ALL
    SELECT point_2, (b + cost)::numeric, concat(c, ',', point_2)
    FROM graph, r
    WHERE cost = least(cost) AND point_1 = a AND (strpos(c, point_2) = 0 OR (point_2 = 'A' AND char_length(c) = 8))
    )SELECT b AS total_cost, concat(lower(c), '}') AS tour FROM r WHERE b = (SELECT min(b) FROM r WHERE char_length(c) = 10) AND char_length(c) = 10
    UNION ALL
    SELECT b AS total_cost, concat(lower(c), '}') AS tour FROM r WHERE b = (SELECT max(b) FROM r WHERE char_length(c) = 10) AND char_length(c) = 10;
