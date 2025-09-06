# Day 05 - Piscine SQL

## Задача
1. Создайте простой BTree-индекс для каждого внешнего ключа в нашей базе данных. Шаблон имени должен соответствовать следующему правилу: «idx_{table_name}_{column_name}». Например, BTree-индекс имени для столбца pizzeria_id в таблице `menu` — `idx_menu_pizzeria_id`.
2. Прежде чем продолжить, пожалуйста, напишите SQL-запрос, который возвращает названия пицц и соответствующих пиццерий. Взгляните на пример результата ниже (сортировка не требуется).
| pizza_name | pizzeria_name | 
| ------ | ------ |
| cheese pizza | Pizza Hut |
| ... | ... |
Давайте предоставим доказательство того, что ваши индексы работают с вашим SQL-запросом.
Примером доказательства служит вывод команды `EXPLAIN ANALYZE`.
Пожалуйста, посмотрите на пример вывода команды.
->  Index Scan using idx_menu_pizzeria_id on menu m  (...)
3. Создайте функциональный индекс B-Tree с именем `idx_person_name` для имени столбца таблицы `person`. Индекс должен содержать имена людей в верхнем регистре.
Напишите и предоставьте SQL-запрос с подтверждением (`EXPLAIN ANALYZE`) работоспособности индекса idx_person_name.
4. Создайте более эффективный многостолбцовый B-Tree-индекс с именем `idx_person_order_multi` для SQL-запроса ниже.
    SELECT person_id, menu_id,order_date
    FROM person_order
    WHERE person_id = 8 AND menu_id = 19;
Команда `EXPLAIN ANALYZE` должна вернуть следующий шаблон. Обратите внимание на сканирование «Index Only Scan»!
Index Only Scan using idx_person_order_multi on person_order ...
Пожалуйста, предоставьте SQL-запрос с подтверждением (`EXPLAIN ANALYZE`) работоспособности индекса `idx_person_order_multi`.
5. Создайте уникальный индекс BTree с именем `idx_menu_unique` в таблице `menu` для столбцов `pizzeria_id` и `pizza_name`.
Напишите и предоставьте SQL-код с подтверждением (`EXPLAIN ANALYZE`) работоспособности индекса `idx_menu_unique`.
6. Создайте частично уникальный BTree-индекс с именем `idx_person_order_order_date` в таблице `person_order` для атрибутов `person_id` и `menu_id` с частичной уникальностью для столбца `order_date` для даты `2022-01-01`.
Команда `EXPLAIN ANALYZE` должна возвращать следующий шаблон.
Index Only Scan using idx_person_order_order_date on person_order …
7. Пожалуйста, рассмотрите приведённый ниже SQL-код с технической точки зрения (не обращайте внимания на логическую сторону этого SQL-оператора).
    SELECT
        m.pizza_name AS pizza_name,
        max(rating) OVER (PARTITION BY rating ORDER BY rating ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING) AS k
    FROM  menu m
    INNER JOIN pizzeria pz ON m.pizzeria_id = pz.id
    ORDER BY 1,2;
Создайте новый индекс BTree с именем `idx_1`, который должен улучшить метрику «Время выполнения» этого SQL-кода. Пожалуйста, предоставьте доказательство (`EXPLAIN ANALYZE`) улучшения SQL-кода.
## Срок выполнения
Отведено: 1 день(8 часов).
Дополнительные задачи: отсутствуют.
Выполнено за 1 день.
## Тип проекта
Индивидуальный, весь проект выполнен мной.
## Используемые языки/технологии/библиотеки.
SQL, PostgreSQL.
