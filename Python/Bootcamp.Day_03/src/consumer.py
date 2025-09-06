import argparse
import json
import logging
import time
import sys

sys.path.insert(1, '/Users/burnerwa/Library/Python/3.9/lib/python/site-packages')

import redis

parser = argparse.ArgumentParser()
parser.add_argument("-e", "--env", type=str, default='1000000000,1000000001,1000000002,1000000003,1000000004,1000000005,1000000006')
args = parser.parse_args()
splitted = args.env.split(",")

count = 0
        
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
        count += 1
        d = json.loads(message["data"])
        if str(d["metadata"]["to"]) in splitted and d["amount"] >= 0:
            temp = d["metadata"]["to"]
            d["metadata"]["to"] = d["metadata"]["from"]
            d["metadata"]["from"] = temp
        logging.warning(d)
    if count == 10:
        break
