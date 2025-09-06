 create table graph
 ( id bigint primary key ,
 point_1 varchar not null,
 point_2 varchar not null,
 cost bigint
 );

INSERT INTO graph VALUES (1, 'A', 'B', 10);
INSERT INTO graph VALUES (2, 'B', 'A', 10);
INSERT INTO graph VALUES (3, 'B', 'C', 35);
INSERT INTO graph VALUES (4, 'C', 'B', 35);
INSERT INTO graph VALUES (5, 'B', 'D', 25);
INSERT INTO graph VALUES (6, 'D', 'B', 25);
INSERT INTO graph VALUES (7, 'D', 'C', 30);
INSERT INTO graph VALUES (8, 'C', 'D', 30);
INSERT INTO graph VALUES (9, 'A', 'C', 15);
INSERT INTO graph VALUES (10, 'C', 'A', 15);
INSERT INTO graph VALUES (11, 'A', 'D', 20);
INSERT INTO graph VALUES (12, 'D', 'A', 20);

WITH RECURSIVE r(a,b,c) AS (
    VALUES('A', 0::numeric, '{A')
UNION ALL
    SELECT point_2, (b + cost)::numeric, concat(c, ',', point_2)
    FROM graph, r
    WHERE cost = least(cost) AND point_1 = a AND (strpos(c, point_2) = 0 OR (point_2 = 'A' AND char_length(c) = 8))
    )SELECT b AS total_cost, concat(lower(c), '}') AS tour FROM r WHERE b = (SELECT min(b) FROM r WHERE char_length(c) = 10) AND char_length(c) = 10;
