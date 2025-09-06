# Day 04 - Python Bootcamp

## Задача
Краткий перевод с английского(оригинала задания) - 
1. Написать функцию, которая принимает 3 итерируемых объекта, находит среди них те, которые подходят по заданным параметрам и при их помощи создает предложение по типу "plug cable1 into socket1 using plug1", в котором  plug, socket, cable являются данными итераторами переменными. Количество предложений равняется наименьшей длинне одного из socket, cable итераторов. Итерируемый plug является опциональным и если его длинна меньше двух оставшихся - предложение принимает форму "weld cable4 to socket4 without plug".
2. Создать генератор туррелей при помощи функции `turrets_generator()`, нельзя создавать класс, именно генератор. Параметры "характера" туррелей получают случайное значение от 0 до 100, но должны в сумме между собой давать 100, каждая турель также имеет 3 функции, которые печатают в терминал разные слова, имитирующие их поведение.
3. Написать функцию `emit_gel()`, которая имитирует давление геля. Выбирается произвольное число от 0 до 100 и каждый "шаг" давление повышается или понижается на случайное число от 0 до "шаг"("шаг" является параметром функции). Если давление повышается выше 80, то "направление" поворачивается в другую сторону и теперь каждый шаг сбавляет давление на величину равную ему. Если понижается ниже 20, то наоборот снова начинает расти. Если в любой момент времени отметка опустится ниже 10 или станет выше 90, то случается срочная остановка и программа останавливает действие.
Полная версия в оригинале -
The room turned out to be pretty small. One wall had a large window with a dark behind it.
Chell's eyes widened in surprise as she realised this was actually a monitoring room for the 
test chamber. From the other side.

 "Due to mandatory scheduled maintenance, the appropriate chamber for this testing
 sequence is currently unavailable. Due to the lack of personnel an exception has been made and
 a test subject is required to perform the maintenance," said GLaDOS from the core.

A service manual was lying on the table. Chell quickly run her eyes over it. Most repairs were
meant to be performed by specialized robots, but an AI guiding them went offline after GLaDOS'
main chamber was destroyed. "At least it wasn't COMPLETELY useless," she thought to herself.

 "First, it is required to fix the wiring that was damaged because of an..." GLaDOS made
 a buzzing sound. "Incident."

Chell smirked to herself and continued reading. Apparently, most commands for repair robots in
this system had to be given in forms of *iterators*. There were many things mentioned, like
`map()`, `filter()`, `zip()` and also something called `generator expressions`.

 "I keep track of every cable, socket and plug in any part of the facility," AI continued.
 Chell raised an eyebrow. What was it in her voice, pride? "But due to the lack of visibility
 I currently cannot neither confirm nor deny if the quantity is correct."

A girl with a portal gun moved a chair to the terminal and powered it on.

-----

You need to write a script `energy.py` with a function called `fix_wiring()`, which should accept 
three iterables (you can test the functionality with just lists) called `cables`, `sockets` and 
`plugs`. This function shouldn't make any assumptions about the length of those iterables, which 
may be different. It should return another iterable over strings with commands like:

`plug cable1 into socket1 using plug1`
`weld cable2 to socket2 without plug`

You can see that the only iterator which length doesn't matter is `plugs`, because at the worst
case cables can be welded to sockets. If there is not enough cables or sockets, there is nothing
you can do, so they shouldn't be present in a resulting iterator.

This means, for a code like this:

```
plugs = ['plug1', 'plug2', 'plug3']
sockets = ['socket1', 'socket2', 'socket3', 'socket4']
cables = ['cable1', 'cable2', 'cable3', 'cable4']

for c in fix_wiring(cables, sockets, plugs):
    print(c)
```

the output should be:

```
plug cable1 into socket1 using plug1
plug cable2 into socket2 using plug2
plug cable3 into socket3 using plug3
weld cable4 to socket4 without plug
```

Also, input iterators can contain other non-string datatypes, which should be filtered out. So, for
an input like

```
plugs = ['plugZ', None, 'plugY', 'plugX']
sockets = [1, 'socket1', 'socket2', 'socket3', 'socket4']
cables = ['cable2', 'cable1', False]
```

it should be just

```
plug cable2 into socket1 using plugZ
plug cable1 into socket2 using plugY
```

To have fun, you can get additional points if the body of your function could be written using only
one line (starting with `return`), meaning no block-starting colons (like in `if` conditions or 
`try/except`) are used.

### Exercise 01: Personalities

 "Did you know turrets also have personalities?"

This question caught Chell by surprise. She looked inquiringly at the core.

 "Each one of them is a unique combination of several random variables. Also, they like to sing
 sometimes. And you've destroyed so many of them on the way."

Chell tried really hard to feel pity for gunshot killers. That wasn't easy.

 "Anyway, to reactivate the test chambers that were damaged during an... incident, we have to
 restore the production line. Vital testing apparatus is required to continue the research."

At the side of the table there was a blueprint of turret with a functional description:

```
class: Turret
personality traits: neuroticism, openness, conscientiousness, extraversion, agreeableness
actions: shoot, search, talk
```

The blueprint also had a circle of a coffee mug, a large number 427 and a name 'Stanley' written
in the corner.

-----

You need to implement a generator function for turrets called `turrets_generator()` in a file
called `personality.py`. The tricky part is, you shouldn't describe the Turret class separately
(there is a way to generate *both* the class and the instance dynamically without using the
word `class` at all).

Also, three methods should just print 'Shooting', 'Searching' and 'Talking', correspondently.
Each personality trait should be a random number between 0 and 100, and the sum of all five
for every instance should be equal to 100.

### Exercise 02: Backpressure

 "You're showing a great determination to fix that was broken during the... incident. Well
 done!"

Chell sighed and continued browsing through the data on the terminal. The last warning she saw was
about something called 'repulsion gel', whatever that meant.

 "I see you found our official experimental dietetic pudding substitute. This is the last
 task to be completed without using Handheld Portal Device."

Dietetic substitute? Okay, that wasn't the weirdest thing she saw in Aperture Science labs. Chell
did some more searching and found that the automatic control valve was reset and needed to be
reconfigured.

-----

First, you need to create a file `pressure.py` a generator function `emit_gel()` which should
simulate the measured pressure of a liquid. It should generate an infinite stream of numbers going
from 0 to 100 (values > 100 are considered an error) with a random step sampled from range 
`[0, step]` where `step` is an argument of a generator `emit_gel()`.

Second, you need to follow the guidelines for the pressure control. Operating pressure is supposed
to be between 20 and 80, meaning if a generator at some point emits a value below 20 or above 80
the action should be applied that will reverse the sign of the step. To implement this kind of
valve you need to write another function called `valve()`, which will loop over values of
`emit_gel()` and use `.send()` method to flip the current step sign.

Third, you should implement an emergency break. If a pressure is above 90 or below 10, the
`emit_gel()` generator should be gracefully closed and the script should exit.

Feel free to experiment around and pick a `step` so that your script will run for a few seconds
before exiting. You can add a delay between "pressure measurements" to avoid spending too much
CPU on generating and processing the sequence.

-----

 "Thank you in participating in lab equipment repairs. Please return to the test chamber to
 continue your duty as a test subject."

The window opened and Chell jumped down to the floor from the maintenance room. GLaDOS' voice
sounded a lot louder and more confident now.

 "I'm glad you've changed your mind and agreed that the goals of Aperture Science about
 making the world a better place are more important than your so called 'freedom'."

Chell turned your face to the camera, smiled and covered her ears with her fingers. If her 
calculations were correct, that 'repulsion gel' should start filling up the storage room any second
now. And then things will probably get really loud for a moment.

And then she will definitely find her way out of this place. After all, she was still alive.
## Срок выполнения
Отведено: 5 дней(38 часов).
Дополнительные задачи: отсутствуют.
Выполнено за 1 день.
## Тип проекта
Индивидуальный. Все написано мной.
## Используемые языки/технологии/библиотеки.
Python.
