# Day 01 - Python Bootcamp

## Задача
Краткий перевод с английского(оригинала задания) - 
1. Написать функции `add_ingot(purse)`, `get_ingot(purse)` и `empty(purse)`. purse является словарем(dict) и три этих функции должны манипулировать значениями ключа "gold_ingots" (имитировать добавление, изъятие и опустошение всех золотых слитков и прочего из кошелька).
2. Написать функцию `split_booty`, которая принимает неизвестное количество кошельков, поровну делит количество золота в них и возвращает словари с новыми значениями ключа "gold_ingots".
3. При помощи декоратора модифицировать поведение функций и при каждом применении любой из них печатать слово `SQUEAK`.
Полная версия в оригинале -
"So, Bert, I see you are a distinguished gentleman!" proclaimed William. "So how would you design my purse then?"

You need to write functions `add_ingot(purse)`, `get_ingot(purse)` and `empty(purse)` that accept
a purse (a dictionary, which is, strictly speaking, a `typing.Dict[str, int]`) and return a purse 
(an empty dict in case of `empty(purse)`). They should not make assumptions about the content of 
the purse (it can be empty or store something completely different, like "stones").

Also, your functions shouldn't have side effects. This means, an object passed as an argument 
should not be modified inside a function. Instead, a new object should be returned. Thus, you 
*shouldn't use the code written by Tom*, as it makes a *direct assignment* to a field inside 
a purse. You should return a *new dict instance* with an updated number inside it instead.

So, a function composition like `add_ingot(get_ingot(add_ingot(empty(purse))))` should return
`{"gold_ingots": 1}`. Also, getting an ingot from an empty purse shouldn't lead to an error and 
should just return an empty one.

Side note: we are only interested in gold ingots in this task, so it doesn't really matter what 
happens with the rest of the stuff inside the purse. You can preserve it or throw away.

### Exercise 01: Splitwise

 "Just wait a moment, kind sirs," said Tom. "How all this will help us split the booty? If after the hunt we have several purses, then how can we decide who gets what?"
 
 "Do not worry, my friend!" William gently slapped Tom on the shoulder. "A guiding star will help us!"
 
 "A star? How?"

 "How does one implement a function so that it can accept both one, two or many objects as arguments?"

 "Oh, I get it now, thank you!" And then Tom and William have started working on an honest algorithm.

You need to write a function named `split_booty`, which will receive any number of purses (dictionaries) as arguments. Purses in arguments can possibly contain various items, but our men of honor are only interested in gold ingots (named `gold_ingots` as in examples above). Number of ingots can be zero or positive integer.

This function should return three purses (dictionaries) back so that in any two of three purses the difference between the number of ingots is no larger than 1. For example, if the booty includes `{"gold_ingots":3}`, `{"gold_ingots":2}` and `{"apples":10}`, then function should return `({"gold_ingots": 2}, {"gold_ingots": 2}, {"gold_ingots": 1})`.

While implementing this function you still shouldn't use direct assignment to fields inside dictionaries. You can reuse functions you wrote in EX00 instead. 

## Chapter VI
### Exercise 02: Burglar Alarm

Bilbo Baggins, or "The Burglar", how he now liked to call himself internally, was hiding in the bushes and quietly listening to three giant trolls, discussing pretty interesting things. He didn't really understand the most of it, but at least it was about booty, purses and ingots. So, he pretty much convinved himself already that this discussion is somehow related to his "specialty", when he decided to steal William's purse. And when his hand was already grabbing it from a stump (trolls were still in the middle of a pretty heated discussion) it suddenly made a very loud squeak.

And he immediately realized that now three pairs of troll eyes are staring directly at him.

 "Sir William," after a short pause started Bert, looking at hobbit who just froze in place out of fear, "I see you've managed to establish some certain protective measures. That's brilliant! Is it some additional feature in your functional design?"

 "Well," William responded, "I believe you've already noted that this particular purse is, so to say, pretty "squeaky". That's because if someone tries some funny business with it then it makes a sound and I immediately know about it. It's due to its specific, hmm, "decoration"..."

 So far you wrote several functions (`add_ingot(purse)`, `get_ingot(purse)` and `empty(purse)`) for the purse design, but now you need to figure out a way to add some new behaviour to all of them - whenever any of them is called a word `SQUEAK` should be printed. The trick is that you can't modify the body of those functions, but still provide that alarm. The clue that William mentioned about "specific decoration" can possibly help you with that.
## Срок выполнения
Отведено: 5 дней(38 часов).
Дополнительные задачи: отсутствуют.
Выполнено за 1 день.
## Тип проекта
Индивидуальный. Все написано мной.
## Используемые языки/технологии/библиотеки.
Python.
