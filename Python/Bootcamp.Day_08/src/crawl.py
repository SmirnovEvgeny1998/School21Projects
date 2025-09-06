import sys

sys.path.insert(1, '/Users/burnerwa/Library/Python/3.11/lib/python/site-packages')

import argparse
import httpx
import json
import asyncio
import time
import logging


parser = argparse.ArgumentParser()
parser.add_argument("--sites", nargs="+")
args = parser.parse_args()

json_data = json_data = json.dumps({"addresses": args.sites})
r = httpx.post('http://127.0.0.1:8888/api/v1/tasks/', data=json_data)
print(r.content)

async def poster(site, ID):
    r = await asyncio.to_thread(httpx.post, site, data=ID)
    
async def getter(site):
    r = await asyncio.to_thread(httpx.get, site)
    return r

async def startup_the_json():
    global r
    json_data = json.dumps({"ID" : json.loads(r.content)["ID"]})
    json_starter = asyncio.create_task(poster('http://127.0.0.1:8888/api/v1/tasks/try/', json_data))
    await asyncio.gather(json_starter)
    
async def check_if_done():
    global r
    ID = json.loads(r.content)["ID"]
    task = asyncio.create_task(getter('http://127.0.0.1:8888/api/v1/tasks/' + str(ID)))
    result = await asyncio.gather(task)
    while json.loads(result[0].content)['status'] != 'ready':
        time.sleep(1)
        print(json.loads(result[0].content)['status'])
        task = asyncio.create_task(getter('http://127.0.0.1:8888/api/v1/tasks/' + str(ID)))
        result = await asyncio.gather(task)
    print(json.loads(result[0].content)['status'])
    for address in json.loads(result[0].content)['addresses']:
        print(address)
    

async def async_checks():
    tasks = []
    tasks.append(asyncio.create_task(check_if_done()))
    tasks.append(asyncio.create_task(startup_the_json()))
    await asyncio.gather(*tasks)

if json.loads(r.content)['addresses']['addresses'] != None:
    asyncio.run(async_checks())
else:
    logging.error("Empty list was given")
