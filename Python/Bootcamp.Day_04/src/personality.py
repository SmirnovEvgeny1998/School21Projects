import random

def shooting():
    print('shooting')

def searching():
    print('searching')

def talking():
    print('talking')

def turrets_generator():
    ceil = 100
    num1 = random.randint(0, ceil)
    ceil -= num1
    num2 = random.randint(0, ceil)
    ceil -= num2
    num3 = random.randint(0, ceil)
    ceil -= num3
    num4 = random.randint(0, ceil)
    ceil -= num4
    num5 = ceil
    yield type("Geeks", (object,), {
        "Class": "turret",
        "neuroticism": num1,
        "openness": num2,
        "conscientiousness": num3,
        "extraversion": num4,
        "agreeableness": num5,


        # member functions
        "shoot": shooting,
        "search": searching,
        "talk": talking
    })

# creating objects
obj = next(turrets_generator())
print(obj.Class)
print(obj.neuroticism)
print(obj.openness)
print(obj.conscientiousness)
print(obj.extraversion)
print(obj.agreeableness)
obj.shoot()
obj.search()
obj.talk()
