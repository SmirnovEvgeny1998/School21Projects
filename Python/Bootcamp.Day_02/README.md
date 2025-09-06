# Day 02 - Python Bootcamp

## Задача
Краткий перевод с английского(оригинала задания) - 
1. Создать новый класс `Key` и при помощи магических методов сделать так, чтобы его объекты при сравнении с числами были больше 9000, имели поведения типа 'list' имеющий длинну 1337 и на индексе 404 имеющий цифру 3, key.passphrase должен быть "zax2rulez" и при преобразовании объекта в класс строки он должен принимать значение "GeneralTsoKeycard".
2. Имплементировать игру. Правила - два человека в течение десяти раундов сотрудничают или пытаются обмануть друг друга. Если в раунде они оба выбирают сотрудничество - оба получают 2 очка, оба жульничают - никто не получает ничего, если же 1 сотрудничает, а 2 обманывает, то обманщик получает 3 очка, а другой игрок теряет одно. Необходимо создать 7 классов: класс игры и игрока и 5 типов игроков, для которых класс игрока - родительский. После этого при помощи функции 'play' имитировать 10 игр по 10 раундов между различными типами игроков и написать функцию таблицы лидеров, которая показывала бы самые успешние типы игроков по статистике.
Полная версия в оригинале -
```
AssertionError: len(key) == 1337
AssertionError: key[404] == 3
AssertionError: key > 9000
AssertionError: key.passphrase == "zax2rulez"
AssertionError: str(key) == "GeneralTsoKeycard"
```
### Exercise 00: Gaining Access

Our hero put his backpack on the ground and got out a thick book called
"Dean's Electronics". It mostly covered hardware, but there was a whole
section onprogramming. He read that "assert" is a special statement which
sole purpose is to check if a certain condition is met. Apparently, in this
case the system expected that the introduced digital key would pass several
checks before opening the door.

But it still was weird. First two lines implied that 'key' is a list, but 
then comparing it with number 9000 ruined that assumption completely. Looks
like a custom data type had to be introduced.

At the final chapter, the book also mentioned that custom types can be 
introduced using classes. There was still one thing though - a lockpick
he had had a very tiny memory and couldn't really store 1337 elements in it,
even worse, it couldn't hold 404, either. Was there a way to bypass it?

The last page in this chapter was torn and lost decades ago, only a small
piece left. It just had one line which looked like this:

`__magic_methods__`

with double underscores on both sides.

The Chosen One thought about all this for whole five minutes, then plugged
the lockpick into his trusty PipBoy and started coding.

-----

You need to describe a Python class `Key` so that an instance of this class
would pass the checks listed above. Keep in mind, that your code in this
exercise shouldn't create any containers, neither of size 404 nor less.
Even without it you should be able to pass those checks.

You are encouraged to write an actual set of tests to simulate the key
checking according to the errors above (and to simplify peer review).
This is graded as a bonus.

## Chapter V
### Exercise 01: Morality

Finally, the massive door started to open! Just in case, the Chosen One 
put his hand on the holster. Last time opening such door lead to a long
shootout with ghouls.

But the space behind the door was empty. And clean. In fact, there wasn't
much space there at all - just one small room with a terminal and no way
deeper into the vault. 

The screen on a terminal lit up showing a logo of something called "ZAX 2.0"
and a strange synthetic voice echoed through the room.

 "Greetings, visitor! I see the war has ended and now it's my turn
 to take over!"

Our hero was stunned for a moment, but this wasn't the first time he
encountered a sophisticated security system.

 "Hi, what do you mean by "taking over"?"

 "My name is ZAX and I was created to restore the humanity to its
 glory when the bad times end! Welcome, human, now let's revive the world
 to its glory!"

...After about an hour of discussion the picture started to come together.
ZAX was created by some brilliant scientists long before the war to solve
the problems of distribution of limited resources. When the fallout came
to the horizon, it was reprogrammed based on the same principles to "rule
the world", so to speak, which meant "provide optimizations for supply
chains". Basically, the whole vault was just a single big computer.

The artificial intelligence started asking the Chosen One many questions 
about what's going on on the surface, and also about how long will it take
to bring the current "big shots" here, into the vault, so it could start 
its "life's work".

 "I'm currently processing the thing you people are calling 
 'Prisoner's Dilemma'," acknowledged ZAX. "During my time here based on
 all the information I had I've started classifying people by their
 behavior."

ZAX told about the simple game with candy, where there is a machine that
controls the supply of candy for two groups of people based on whether 
one or both of two operators put one in it:

|  | Both cooperate | 1 cheats, 2 cooperates | 1 cooperates, 2 cheats | Both cheat |
|------------|----------|----------|----------|---------|
| Operator 1 | +2 candy | +3 candy | -1 candy | 0 candy |
| Operator 2 | +2 candy | -1 candy | +3 candy | 0 candy |

So, if everyone is cooperating and puts candy in a machine as agreed,
everyone gets a reward. But both participants also have a temptation to
cheat and only pretend to put a candy into machine, because in this case
their group will get 3 candy back, just taking one candy from a second
group. The problem is, if both operators decide to play dirty, then nobody
will get anything.

Also, ZAX mentioned five models of behavior that it used to run experiments:

| Behavior type | Player Actions                                                                                                                                                                                         |
|---------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Cheater       | Always cheats                                                                                                                                                                                          |
| Cooperator    | Always cooperates                                                                                                                                                                                      |
| Copycat       | Starts with cooperating, but then just repeats whatever the other guy is doing                                                                                                                         |
| Grudger       | Starts by always cooperating, but switches to Cheater forever if another guy cheats even once                                                                                                          |
| Detective     | First four times goes with [Cooperate, Cheat, Cooperate, Cooperate],  and if during these four turns another guy cheats even once -  switches into a Copycat. Otherwise, switches into Cheater himself |

-----

To finish the experiment with ZAX, you need to model a system with seven
classes - `Game`, `Player` and five behavior types (subclassed from `Player`).

The skeleton for a `Game` class looks like this:

```python
from collections import Counter

class Game(object):

    def __init__(self, matches=10):
        self.matches = matches
        self.registry = Counter()

    def play(self, player1, player2):
        # simulate number of matches
        # equal to self.matches

    def top3(self):
        # print top three
```

Here, `registry` is used to keep track of the current number of candy
during the game, while `player1` and `player2` are instances of 
subclasses of `Player` (each being one of 5 behavior types). Calling 
`play()` method of a `Game` instance should perform a simulation
of a specified number of matches between players of a given behavior.

Method `top3()` should print current top three player's behaviors
along with their current score, like:

```
cheater 10
detective 9
grudger 8
```

By default, your code when run should simulate 10 matches (one call of
`play()`) between every pair of two players with *different* behavior
types (total 10 rounds by 10 matches each, no matches between two
copies of the same behavior) and print top three winners after the 
whole game.

You are strongly encouraged to experiment around with different
behaviors and writing your own behavior class (this is graded as a
bonus). You can get even more bonus points if an instance of your 
class performs better in the same "contest between each pair of
players" check that at least three of five provided behaviors.

Don't forget that the only thing a player can do on each turn is
either cooperate or cheat, based on a history of a current game.

-----

...A couple of hours later the Chosen One left the vault with ZAX,
closing the door behind him. He got what he wanted - quite a few new
interesting thoughts to wrap the head around. And about ruling the
world...in its current state the world wasn't ready for something
like ZAX. Not like wild raiders would ever pass the crown to a tin
can. Not like the Chosen One himself would.
## Срок выполнения
Отведено: 5 дней(38 часов).
Дополнительные задачи: отсутствуют.
Выполнено за 2 дня.
## Тип проекта
Индивидуальный. Все написано мной.
## Используемые языки/технологии/библиотеки.
Python.
