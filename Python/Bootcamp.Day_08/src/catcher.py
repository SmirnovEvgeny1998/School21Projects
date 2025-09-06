import json
import logging
import random
import time
import os
import sys

sys.path.insert(1, '/Users/burnerwa/Library/Python/3.11/lib/python/site-packages')

import redis

        
import redis
r = redis.Redis(
    host='127.0.0.1',
    port=6379,
    decode_responses=True
)
mobile = r.pubsub()
mobile.subscribe('army-camp-1')
for message in mobile.listen():
    if message["data"] != 1:
        d = json.loads(message["data"])
        if "" in d:
            d["Not a site"] = d.pop("")
        logging.warning(d)
