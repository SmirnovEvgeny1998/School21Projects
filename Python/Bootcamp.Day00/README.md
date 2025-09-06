# Day 00 - Python Bootcamp

## Задача
Краткий перевод с английского(оригинала задания) - 
1. Создать программу, которая получает набор символов и определяет, начинается ли строка с ровно пяти нулей и длинной в 32 символа. Строки подходящие под этот критерий вывести в терминал.
2. Программа получает для обработки предложение. Необходимо вывести в терминал слово, которое получается из конкатенации всех первых букв этого предложения.
3. Программа получает набор символов для обработки. Она должна определить, содержит ли этот набор в себе паттерн буквы "М", состоящий из символов звездочки(*).
Полная версия в оригинале -
- Correct lines are 32 characters long
- They start with exactly 5 zeroes, so e.g. line starting with 6 zeroes is NOT
  considered correct

So, for the example above your script should print:

```
00000254b208c0f43409d8dc00439896
0000085a34260d1c84e89865c210ceb4
0000071f49cffeaea4184be3d507086v
```

Your code should accept the number of lines as an argument, like this:

`~$ cat data_hashes_10lines.txt | python blocks.py 10`

This way the program will stop when it processed 10 lines. Keep in mind that in this approach
the program may hang if the number of lines in a file is smaller than the one in the argument.
This is not considered an error.

### Exercise 01: Decypher

This time inspector was a lot more calm, even a bit cheerful. In the crime lab
they've figured out that the blockchain implementation used by criminals was
really poorly designed, so even in these circumstances they've managed to pull
some documents out of the distributed network.

But then one incoming SMS changed everything. 

 "Sherlock! They want to blow up several buildings in London! Today!"

Inspector jumped up from the armchair and started nerviously walking back and 
forth.

 "Give me more."
 
 "One of the documents had a list of locations and directions. At first we
  thought that it is a list of their meeting points, but then one operative
  found a hidden smartphone on one of those locations. It had instructions 
  for the engineers for setting up the device, but no exact locations. Only 
  a whole bunch of very weird emails."
 
 "Can I see?"
 
 "Sure."

This WAS weird. Emails consisted of some strange texts, like "The only way
everyone reaches Brenda rapidly is delivering groceries explicitly" or 
"Britain is Great because everyone necessitates".

After about two minutes of silently looking at those emails, Sherlock
grabbed his laptop again and started furiously typing. In next minute, he
turned it around and showed the list to Lestrade.

 "I think these are the locations where bombs will be planted. The
  algorithm is actually pretty simple."

Could you find out how Sherlock figured it out and write a Python script
that can be used to decrypt any messages like that? (If you want to solve
this mystery yourself - don't peek at the checklist right away). It should
be launchable like this:

`~$ python decypher.py "Have you delivered eggplant pizza at restored keep?"`

and print out the answer as a single word without spaces.

## Chapter VI
### Exercise 02: Track and Capture

 "But almost all these are major tourist attractions! Of course we do have
  cameras all over them, but there are dozens, maybe hundreds of people
  there! How do we find those we're looking for?"
 
 "I think I know the person who is behind all this."
 
 "Ehh... You do? How?"
 
 "Doesn't matter for now. It's just a guess. But I also happen to know,
  that all goons who work for him and perform dirty work also have a pretty
  distinct tattoo on the side of the neck. Can your cameras capture that?"
 
 "Yes, Sherlock, but we don't have the proper recognition software in place..."
 
 "I think we still can do it. Just use a simple ASCII filter on the image
  and we will solve it from there."
 
 "Which filter?"
 
 "Just tell your technicians. They will know what to do."

So, as an input your code is given a 2d "image" as text in a file `m.txt`. File contains five
characters over three lines, like this:

```
*d&t*
**h**
*l*!*
```

You may notice that there is a pattern of stars here, with a letter M. All
your code has to do is to print 'True' if this M-pattern exists in a given
input image or 'False' otherwise. Other characters (outside the M pattern)
should be different, so these examples should print out 'False':

```
*****
*****
*****
```

```
*s*f*
**f**
*a***
```

If a given pattern is not 3x5, then 'Error' word should be printed instead.
The file with code should be named `mfinder.py`.

When you do that, Lestrade will upload that code to police servers and all
terrorists will be located by the cameras in no time.

And Sherlock will get ready for some another challenge organized by a 
mysterious man hiding behind a letter M. Sometimes it seems like these
puzzles were specifically engineered for him to solve...
## Срок выполнения
Отведено: 5 дней(38 часов).
Дополнительные задачи: отсутствуют.
Выполнено за 1 день.
## Тип проекта
Индивидуальный. Все написано мной.
## Используемые языки/технологии/библиотеки.
Python.
