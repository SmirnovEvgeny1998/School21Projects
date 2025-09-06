import load_questions
import interrogation
import pseudo_manual
import threading
import os

def test_load():
    load_questions.CreateQuestionDB()
    assert os.path.isfile("questions.db")

def test_db_content():
    db = load_questions.VKTest.select()
    assert len(db) == 10
    assert db[0].question == "Ребенок показывает вам свою коллекцию бабочек и банку для убийств, ваша реакция?"
    assert db[7].weight_1 == 2
    assert db[9].answer_3 == "Не знаю"
        
'''def test_ask_questions():
    threads = []
    threads.append(threading.Thread(target=interrogation.ask_questions))
    threads.append(threading.Thread(target=pseudo_manual.imitate_right))
    for thread in threads:
        thread.start()
    for thread in threads:
        thread.join()
    assert interrogation.replicancy == 6.75
        
def test_ask_questions_2():
    threads = []
    threads.append(threading.Thread(target=interrogation.ask_questions))
    threads.append(threading.Thread(target=pseudo_manual.imitate_wrong))
    for thread in threads:
        thread.start()
    for thread in threads:
        thread.join()
    assert interrogation.replicancy == 1.125
    
def test_insert():
    threads = []
    threads.append(threading.Thread(target=interrogation.check_insert))
    threads.append(threading.Thread(target=pseudo_manual.imitate_insert))
    for thread in threads:
        thread.start()
    for thread in threads:
        thread.join()
    assert interrogation.result == 4'''
    
def test_check_magnitude():
    res = interrogation.offset_magnitude(-1,66,234,5)
    assert res == 1
    res = interrogation.offset_magnitude(-1,-66,-234,-5)
    assert res == 0.5625
    res = interrogation.offset_magnitude(5551,5566,5234,5555)
    assert res == 5.0625
    

