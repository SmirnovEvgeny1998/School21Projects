import json
import logging
import random
import time
import os
import sys

#sys.path.insert(1, '/Users/burnerwa/Library/Python/3.9/lib/python/site-packages')

import redis

r = redis.Redis(
    host='127.0.0.1',
    port=6379,
    decode_responses=True
)

for i in range(10):
    data1 = {"metadata": {"from": random.randint(1000000000, 9999999999), "to": 1000000000 + i}, "amount": -4 + i}
    logging.warning(data1)
    with open('transactions.json', 'w') as f:
        json.dump(data1, f, indent=4)
    with open('transactions.json') as f:
        r.publish("army-camp-1", f.read())
    time.sleep(1)
    os.remove('transactions.json')
