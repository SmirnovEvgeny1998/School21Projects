SELECT * FROM menu;

UPDATE menu
SET price = (price - (price / 10))::int
WHERE pizza_name = 'greek pizza';

SELECT * FROM menu;