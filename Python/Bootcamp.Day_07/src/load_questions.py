from peewee import *

db = SqliteDatabase('questions.db')


class VKTest(Model):
    """
    Class to repsesent the question, answers and their weight. Inherited from peewee.Model for db creation.
    """
    question = CharField()
    answer_1 = CharField()
    answer_2 = CharField()
    answer_3 = CharField()
    answer_4 = CharField()
    weight_1 = IntegerField()
    weight_2 = IntegerField()
    weight_3 = IntegerField()
    weight_4 = IntegerField()

    class Meta:
        """
        Class of metadata(db name, password etc)
        """
        database = db


def CreateQuestionDB():
    """
    Creates set of predefined questions.
    
    :return: Nothing.
    """
    VKTest.drop_table()
    VKTest.create_table()
    VKTest.create(question="Ребенок показывает вам свою коллекцию бабочек и банку для убийств, ваша реакция?",
                  answer_1="Безразличие",
                  answer_2="Я разозлюсь на ребенка",
                  answer_3="Я скажу, что у него очень красивая коллекция",
                  answer_4="Я переговорю с его родителями на эту тему",
                  weight_1=-2,
                  weight_2=2,
                  weight_3=0,
                  weight_4=1)
    VKTest.create(question="Человека определяет форма или мысль?",
                  answer_1="Форма",
                  answer_2="Мысль",
                  answer_3="Ни одно",
                  answer_4="Оба в некоторой степени",
                  weight_1=1,
                  weight_2=-1,
                  weight_3=1,
                  weight_4=2)
    VKTest.create(question="На рельсах перед движущемся поездом лежат 5 человек, перед вами рычаг, который может повернуть поезд на пути, где лежит один человек, что вы сделаете?",
                  answer_1="Я ничего не буду делать",
                  answer_2="Я поверну рельсы",
                  answer_3="Я попытаюсь привлечь внимание машиниста",
                  answer_4="Я уйду",
                  weight_1=-1,
                  weight_2=2,
                  weight_3=1,
                  weight_4=-2)
    VKTest.create(question="Человек ворвался в вашу квартиру и угрожает смертью вашей матери, что вы будете делать?",
                  answer_1="Сбегу",
                  answer_2="Брошусь защищать ее",
                  answer_3="Заболтаю его",
                  answer_4="Ничего",
                  weight_1=-1,
                  weight_2=1,
                  weight_3=1,
                  weight_4=-1)
    VKTest.create(question="Вы идете по корридору и из-за своей невнимательности бьетесь мизинцем об тумбочку, вам очень больно, ваши действия?",
                  answer_1="Пойду дальше",
                  answer_2="Ударю тумбочку",
                  answer_3="Переставлю тумбочку в другое место",
                  answer_4="Запомню этот случай, чтобы в будущем быть осторожнее",
                  weight_1=-3,
                  weight_2=3,
                  weight_3=0,
                  weight_4=-1)
    VKTest.create(question="Незнакомый человек машет рукой, вы машете рукой в ответ, но оказывается, что он приветсвовал кого-то стоящего у вас за спиной, что вы чувствуете?",
                  answer_1="Смущение",
                  answer_2="Злость",
                  answer_3="Смех",
                  answer_4="Ничего",
                  weight_1=2,
                  weight_2=2,
                  weight_3=-1,
                  weight_4=-1)
    VKTest.create(question="Какая система исчисления самая удобная?",
                  answer_1="Двоичная",
                  answer_2="Десятичная",
                  answer_3="Шестнадцатиричная",
                  answer_4="Затрудняюсь ответить",
                  weight_1=0,
                  weight_2=0,
                  weight_3=-2,
                  weight_4=0)
    VKTest.create(question="Вы находитесь в пустыне и находите идущую вам навстречу черепаху, вы переворачиваете ее на панцирь, она беспоможно раскачивается, пытаясь встать на лапы под палящим солнцем, но безуспешно, вы не помогаете ей, почему?",
                  answer_1="Я хотел позабавиться",
                  answer_2="Я не знаю",
                  answer_3="Не люблю черепах",
                  answer_4="Я этого не делал",
                  weight_1=2,
                  weight_2=0,
                  weight_3=1,
                  weight_4=-3)
    VKTest.create(question="Опишите одним словом свои отношение с родителями",
                  answer_1="Отсутствие",
                  answer_2="Любовь",
                  answer_3="Ненависть",
                  answer_4="Затрудняюсь ответить",
                  weight_1=0,
                  weight_2=1,
                  weight_3=0,
                  weight_4=-2)
    VKTest.create(question="Вы верите в существование бога, пустит ли он вас на небеса?",
                  answer_1="Да",
                  answer_2="Нет",
                  answer_3="Не знаю",
                  answer_4="Я не верю в бога, рая не существует",
                  weight_1=1,
                  weight_2=-1,
                  weight_3=1,
                  weight_4=-3)
