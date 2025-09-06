SELECT * FROM pg_indexes WHERE indexname = 'idx_person_visits_person_id';
SELECT * FROM pg_indexes WHERE indexname = 'idx_person_visits_pizzeria_id';
SELECT * FROM pg_indexes WHERE indexname = 'idx_menu_pizzeria_id';
SELECT * FROM pg_indexes WHERE indexname = 'idx_person_order_person_id';
SELECT * FROM pg_indexes WHERE indexname = 'idx_person_order_menu_id';

SET enable_seqscan TO off;
EXPLAIN ANALYZE SELECT menu.pizza_name, pizzeria.name FROM pizzeria
LEFT JOIN menu ON menu.pizzeria_id = pizzeria.id;
SET enable_seqscan TO on;

/*
Команда выше показывает, что индексы были успешно добавлены, ниже объяснение почему способ указанный в ридми не работает (по крайней мере в моем случае)
Теперь мы выполним команду EXPLAIN SELECT, чтобы проверить результаты для индексов с предложением WHERE. Это приведет к следующему выводу, в котором говорится: «Seq Scan on emp.» Вы можете задаться вопросом, почему это произошло, когда вы используете индексы.

Причина: планировщик Postgres может отказаться от индекса по разным причинам. Стратег большую часть времени принимает оптимальные решения, даже если причины не всегда ясны. Это нормально, если поиск по индексу используется в некоторых запросах, но не во всех. Записи, возвращаемые из любой таблицы, могут различаться в зависимости от фиксированных значений, возвращаемых запросом. Из-за этого сканирование последовательности почти всегда происходит быстрее, чем сканирование индекса, что указывает на то, что, возможно, планировщик запросов был прав, определив, что стоимость выполнения запроса таким образом снижается.
можно использовать cluster numbers using idx_numbers_numbercol; чтобы доказать что индексы работают но это изменит упорядоченность*/