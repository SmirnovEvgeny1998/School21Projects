import sys

sys.path.insert(1, '/Users/burnerwa/Library/Python/3.11/lib/python/site-packages')

import asyncio
import time
import aiohttp
from aiohttp import ClientSession, web
from pydantic import BaseModel
import uuid
import peewee
import json
import httpx
import os.path
import datetime
import redis
import logging
from urllib.parse import urlparse



r = redis.Redis(
    host='127.0.0.1',
    port=6379,
    decode_responses=True
)

domains = {}

class UserCreate(BaseModel):
    addresses : list[str]
    
class PostAdd(BaseModel):
    res : str


async def gather_responses(url):
    async with ClientSession(connector=aiohttp.TCPConnector(ssl=False)) as session:
        try:
            async with session.get(url=url) as resp:
                return url + " " + str(resp.status)
        except:
            return url + " 404"

async def take_sites(user_data: UserCreate):
    ID = int(uuid.uuid4())
    data = await user_data.json()
    print(data)
    
    return_data = {
        "status": "running",
        "ID": ID,
        "addresses": data,
    }
    with open("results/" + str(ID) + "_data.json", "w") as outfile:
        outfile.write(json.dumps(data, indent=4))
    return web.json_response(return_data, status=201)
    
async def write_result_file(data):
    pass

async def return_results(request):
    ID = "{}".format(request.match_info['ID'])
    res = os.path.isfile("results/" + str(ID) + '.json')
    if res:
        f = open("results/" + str(ID) + '.json')
        data = json.load(f)
        f.close()
        parced = []
        for site in data:
            parced.append(urlparse(site).netloc)
        for p in parced:
            if p not in domains:
                domains[p] = 0
        for p in parced:
            domains[p] += 1
        with open('transactions.json', 'w') as f:
            json.dump(domains, f, indent=4)
        with open('transactions.json') as f:
            r.publish("army-camp-1", f.read())
        os.remove('transactions.json')
        return_data = {
            "status": "ready",
            "ID": int(uuid.uuid4()),
            "addresses": data,
        }
        return web.json_response(return_data, status=200)
    else:
        return_data = {
            "status": "running",
            "ID": int(uuid.uuid4()),
            "addresses": "not ready",
        }
        return web.json_response(return_data, status=200)
    

async def add_results(res : UserCreate):
    ID = await res.json()
    tasks = []
    f = open("results/" + str(ID["ID"]) + '_data.json')
    all_data = json.load(f)
    f.close()
    for address in all_data['addresses']:
        tasks.append(asyncio.create_task(gather_responses(address)))
    results = await asyncio.gather(*tasks)
    print(results)
    await asyncio.sleep(2)
    with open("results/" + str(ID['ID']) + ".json", "w") as outfile:
        outfile.write(json.dumps(results, indent=4))
    return web.json_response(status=200)

async def main():
    app = web.Application()
    app.add_routes([web.post('/api/v1/tasks/', take_sites)])
    app.add_routes([web.get('/api/v1/tasks/{ID}', return_results)])
    app.add_routes([web.post('/api/v1/tasks/try/', add_results)])
    runner = web.AppRunner(app)
    await runner.setup()
    site = web.TCPSite(runner, 'localhost', 8888)
    await site.start()

    while True:
        await asyncio.sleep(3600)

if __name__ == '__main__':
    asyncio.run(main())

