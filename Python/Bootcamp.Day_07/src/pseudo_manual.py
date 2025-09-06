import time
import pyautogui

def imitate_right():
    """
    Imitates person who using keyboard and writes right parametrs(those, who dont create exeptions or loops in input). Used for test_ask_questions

    :return: Nothing, just imitates keyboard user.

    """
    for i in range(50):
        time.sleep(0.1)
        pyautogui.write('2')
        pyautogui.press('enter')
        
def imitate_wrong():
    """
    Imitates person who using keyboard and writes different wrong parametrs(those, who create exeptions or loops in input) and then the right one. Used for test_ask_questions_2.

    :return: Nothing, just imitates keyboard user.

    """
    for i in range(50):
        time.sleep(0.1)
        pyautogui.write('20000')
        pyautogui.press('enter')
        time.sleep(0.1)
        pyautogui.write('-1')
        pyautogui.press('enter')
        time.sleep(0.1)
        pyautogui.write('one')
        pyautogui.press('enter')
        time.sleep(0.1)
        pyautogui.write('3')
        pyautogui.press('enter')

def imitate_insert():
    """
    Imitates person who using keyboard and writes different wrong parametrs(those, who create exeptions or loops in input) and then the right one. Used for test_insert.

    :return: Nothing, just imitates keyboard user.

    """
    time.sleep(0.1)
    pyautogui.write('stringy')
    pyautogui.press('enter')
    time.sleep(0.1)
    pyautogui.write(4.5)
    pyautogui.press('enter')
    time.sleep(0.1)
    pyautogui.write(200000)
    pyautogui.press('enter')
    time.sleep(0.1)
    pyautogui.write(4)
    pyautogui.press('enter')
