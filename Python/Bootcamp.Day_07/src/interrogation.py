from peewee import *
from load_questions import VKTest


def ask_questions():
    """
    Starts the questioning. Takes list of questions and answers from pre-formed db and puts them into terminal in human-readable form. Takes answers and parametrs from input() and on their basis gives a decision about user: is he replicant or not. Also creates global replicancy for taking answers from threads in tests.
    
    :return: Nothing.
    """
    global replicancy
    replicancy = 0
    for question in VKTest.select():
        ans = 0
        weight = 0
        respiration = 0
        heart_rate = 0
        blushing = 0
        pupils_dilation = 0
        print(question.question)
        print("1", question.answer_1)
        print("2", question.answer_2)
        print("3", question.answer_3)
        print("4", question.answer_4)
        while ans == 0:
            try:
                ans = int(input())
                if not 1 <= ans <= 4:
                    print("Недопустимая форма ответа, введите цифру от 1 до 4")
                    ans = 0
            except Exception as e:
                print("Недопустимая форма ответа, введите цифру от 1 до 4")
        if ans == 1:
            weight = question.weight_1
        elif ans == 2:
            weight = question.weight_2
        elif ans == 3:
            weight = question.weight_3
        elif ans == 4:
            weight = question.weight_4
        print("Enter BPM after question")
        respiration = check_insert(0, 60)
        print("Enter heart rate after question")
        heart_rate = check_insert(0, 300)
        print("Enter blush level after question")
        blushing = check_insert(1, 6)
        print("Enter pupils dilation in mm after question")
        pupils_dilation = check_insert(2, 8)
        weight *= offset_magnitude(respiration, heart_rate, blushing, pupils_dilation)
        replicancy += weight
    if replicancy >= 0:
        print("Human ", str(replicancy))
    else:
        print("Replicant ", str(replicancy))


def check_insert(min, max):
    """
    Checks user input with given parametrs. Input always must be int, min and max is a range for qualified answers. Also creates global result for taking answers from threads in tests.
    
    :param min: Creates a lower boundary for numbers, after any input less than min function will ask for input again.
    :type min: int
    :param max: Creates a high boundary for numbers, after any input more than max function will ask for input again.
    :type max: int
    :return: Result of correct input.
    :rtype: int
    """
    global result
    result = 0
    while result == 0:
        try:
            result = int(input())
            if not min <= result <= max:
                print("Недопустимая форма ответа, введите целое число между", str(min), " и ", str(max))
                result = 0
        except Exception as e:
            print("Недопустимая форма ответа, введите целое число между", str(min), " и ", str(max))
    return result

def offset_magnitude(bpm, hr, bl, pd):
    """
    Checks if given parametrs are out of normal bounds. Parametrs represent different kinds of human subconsious behavior, every time parameter goes out of normal bounds, function register that and correct the offset of mood by some margin and returns magnitude of emotions after answer.
    
    :param bpm: Breaths per minute that interviewee done.
    :type bpm: int
    :param hr: Number of interviewee's beats of heart.
    :type hr: int
    :param bl: Blush level of interviewee.
    :type bl: int
    :param pd: Size of interviewee's pupils in mm.
    :type pd: int
    :return: Magnitude of emotions.
    :rtype: float
    """
    magnitude = 1
    offset = 0
    if bpm < 12:
        offset -= 1
    elif bpm > 16:
        offset += 1
    if hr < 60:
        offset -= 1
    elif hr > 100:
        offset += 1
    if bl < 2:
        offset -= 1
    elif bl > 5:
        offset += 1
    if pd < 3:
        offset += 1
    elif pd > 6:
        offset += 1

    if offset >= 0:
        for i in range(offset):
            magnitude *= 1.5
    else:
        for i in range(offset * -1):
            magnitude *= 0.75
    return magnitude


