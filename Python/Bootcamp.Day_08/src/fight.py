import asyncio
import random

from enum import Enum, auto
from random import choice


class Action(Enum):
    HIGHKICK = auto()
    LOWKICK = auto()
    HIGHBLOCK = auto()
    LOWBLOCK = auto()


class Agent:

    def __aiter__(self, health=5):
        self.health = health
        self.actions = list(Action)
        return self

    async def __anext__(self):
        return choice(self.actions)


async def fight(agent_number=0):
    agent_1 = Agent()
    agent_1.__aiter__()
    neo = list(Action)
    while agent_1.health != 0:
        a_choise = await agent_1.__anext__()
        await asyncio.sleep(random.randint(5, 25) / 100)
        neo_choise = neo[1]
        if a_choise.value <= 2:
            neo_choise = neo[a_choise.value + 1]
        elif a_choise.value == 3:
            neo_choise = neo[1]
            agent_1.health -= 1
        else:
            neo_choise = neo[0]
            agent_1.health -= 1
        print("Agent:", agent_number + 1, a_choise, " Neo: ", neo_choise, " Agent", agent_number + 1, "Health", agent_1.health)



async def fightmany(n):
    tasks = [asyncio.create_task(fight(_)) for _ in range(n)]
    for i in range(n):
        await tasks[i]

asyncio.run(fightmany(5))
print("Neo wins!")