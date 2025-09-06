# Team 00 - Python Bootcamp

## Задача
Краткий перевод с английского(оригинала задания) - 
1. Написать скрипт `cache_wiki.py` который будет сохранять ссылки, которые находятся на выбранной странице википедии, после чего открывать ссылки и сохранять контактные ссылки уже на этих страницах. Пользователь может установить предел глубины и поиск автоматически останавливается после достижения 1000 сохраненных страниц.
2. Найти кратчайший путь между двумя ссылками. Он может быть логгировать при использовании флага -v.
3. Создать график связей из полученного набора данных.
Полная версия в оригинале -
You need to write a simple calculator module for Python (using the Python C API) with four functions:

During next several minutes, Harry was still explaining to Dumbledore what a 'website' is, but
an old wizard was still unsure about the value of some 'book that can't be touched'.

Harry also tried to explain how some people could follow the links from one article to another and
then end up wondering how did they even get to some other topic. This was a lot easier to relate to
for Dumbledore, and he even started to talk nostalgically about some time when he got completely
lost in a library for a couple of days.

Looks like it was necessary to download some information to illustrate the concept.

-----

You need to write a script called `cache_wiki.py`, which main purpose will be to download pages
from Wikipedia, but the data we're interested in is links in text and 'See also' sections leading
to other pages inside Wikipedia itself. This means, you don't need to download the content, but
only save a graph representation as a JSON file `wiki.json`, so that vertices store pages and
directed edges are links.

You can shoose any Wikipedia article as a default starting position. Also, your code should be
able to receive a name of an existing article as an argument to use instead of a default one
(not necessarily Harry Potter related). So, when it is run like this:

`~$ python cache_wiki.py -p 'Erdős number'`

it should start parsing from this page.
Mind the special symbol encoding in URL.

The goal is to keep following links (only those leading to other Wikipedia pages, NOT to the
outside internet) going *at least three pages deep* down every link. This parameter should be
configurable using `-d`, so default value will be `3`. But if the result is too large (>1000 pages)
your code should stop processing links. If it is too small (<20 pages) then please choose some
other default starting page. Don't forget to keep track of the links leading to the pages you've
already visited. If page A links to page B and page B links to page A - it is two directed graph
edges, not one.

Every page your code visits should be logged to stdout using `logging` Python module with log 
level set to 'INFO'. 

There are no strict requirements on the format of JSON file your code produces, but keep in mind
you'll need to work further with this file in next exercises, so you may consider using existing
Python libraries for graph processing, which support reading/writing JSON files.

To earn some extra score for this exercise, your code can also support storing graph in a [Neo4J
database](https://neo4j.com/download/).

<h3 id="ex01">Exercise 01: Shortcuts</h3>

 "I see. But why are Welsh Corgi so close to King Solomon?"

Harry wanted to say that he has no idea, but then he noticed the smiling eyes of the wizard. 

 "Frankly speaking, I highly doubt it's the weirdest connection there," said the boy, "but
 don't you think, sir, it's..."
 
 "..absolutely fascinating!" finished the wizard. "I think I've underestimated muggles'
 technologies here, well done. Anyway, but how do we figure out how closely are two pages 
 connected to each other?"

Harry thought for a moment. 

 "I assume we can try and find the shortest path from one page to another. This is a pretty
 complicated task with a regular book, but it becomes a lot easier on a serialized graph."

-----

Now you should write the program called `shortest_path.py`, which will need to find the *shortest*
path length between two pages in your serialized database (if these pages are there):

```
~$ python shortest_path.py --from 'Welsh Corgi' --to 'Solomon'
3
~$ python shortest_path.py --from 'Solomon' --to 'Welsh Corgi' --non-directed
3
```

Mind the `--non-directed` flag. It means we treat all links as 'non-directed' or 'bidirected', so
every edge is treated equally in both directions. In this case, a path exists betweeh *any* two
nodes in your serialized graph.

By default (when `--non-directed` is not specified) we are only following the directed edges of 
the graph. This means, not all pages in the database can be reachable from other pages, especially 
if they  have a small amount of inbound links. If the path doesn't exist, your script should print
'Path not found'.

The location of the wiki file should be read from the environment variable named `WIKI_FILE`. If
the database file is not found, the code should print 'Database not found'.

Additionally, please add `-v` flag, which will enable logging of the found path, like this:

```
~$ python shortest_path.py -v --from 'Welsh Corgi' --to 'Solomon'
'Welsh Corgi' -> 'Dog training' -> 'King Solomon's Ring (book)' -> 'Solomon'
3
```

In this exercise, you shouldn't be using an existing implementation of a 'shortest path'
algorithm provided by an existing libraries. Please write it yourself instead.


<h3 id="ex01">Exercise 02: Greatest Magicians</h3>

  "Now I can see the relation with "six handshakes" rule you mentioned. Great magicians 
 can be quite popular, right?"

The boy stared at him, trying to understand what's going on in old wizard's head.

 "Oh, Harry, don't you know the definition of popularity? The more fans you have, the more
 well known overall you are. Like with rock bands."

Dumbledore stood up and went to the entrance of the office. Then he stopped right before the door
and turned back to Harry with a smile.

 "I think all we have to do is visualize the data. To find out who's the greatest, I mean."

Harry raised an eyebrow and looked at the wizard in surprise. It was said pretty loud and looked
like Dumbledore was serious. Find out who is the greatest? Okay, from the graph standpoint it
shouldn't be that hard...

...Draco Malfoy managed to escape from being caught eavesdropping. He was hiding around the corner
from the headmaster's office when Dumbledore left, and now his mind was filled with thoughts about
'greatest wizards'. He firmly decided that the next owl he will send to his father will be about 
connecting Malfoy Manor to the Internet.

-----

Your next script `render_graph.py` should render a visualization your graph of pages (from a file
generated in EX00, also reading it from a `WIKI_FILE` env variable) as a PNG image
`wiki_graph.png`, with nodes and edges. You may use any third-party library for that.

The main rule here is that the size of the node should correspond to the number of incoming 
connections. The more connections - the larger the node in render. This way the 'greatest pages'
in your dataset will be the best visible ones.

You can get additional score in this task if your script optionally can generate not only `.png`
file, but also a `wiki_graph.html` page which will show an interactive visualization of the same
graph. You can use libraries like Altair or Bokeh
to do that.
## Срок выполнения
Отведено: 5 дней(38 часов).
Дополнительные задачи: отсутствуют.
Выполнено за 6 дней.
## Тип проекта
Групповой(занятая позиция - тимлид). Написал скраппер страниц, нахождение кратчайшего пути и преобразование в JSON.
## Используемые языки/технологии/библиотеки.
Python.
