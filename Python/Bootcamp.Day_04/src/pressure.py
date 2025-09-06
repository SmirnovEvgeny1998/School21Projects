import random

def emit_gel(step):
    if type(step) == type(12):
        pressure = 10
        while 9 < pressure < 91:
            yield pressure
            step = yield
            if step >= 0:
                pressure += random.randint(0, step)
            else:
                pressure += random.randint(step, 0)
        if 0 <= pressure <= 100:
            yield pressure
        elif pressure < 0:
            yield 0
        else:
            yield 100

def valve(step, endlessmode = False):
    if not (isinstance(step, int) and isinstance(endlessmode, bool)):
        print("Type error")
    elif -10 <= step <= 10 and endlessmode == False:
        print("With current parameters function will be in endless loop. If you want that, use valve(step,True)")
    else:
        gen = emit_gel(step)
        current = gen.send(None)
        print(current)
        while current < 101:
            if current < 10 or current > 90:
                print("Emergency stop")
                break
            elif current > 80:
                gen.send(abs(step) * -1)
                step = abs(step) * -1
                current = gen.send(step)
                print(current)
            elif current < 20:
                gen.send(abs(step))
                step = abs(step)
                current = gen.send(step)
                print(current)
            else:
                gen.send(step)
                current = gen.send(step)
                print(current)

valve(12)