import re
import json
import os
import sys

# sys.path.insert(1, '/Users/burnerwa/Library/Python/3.9/lib/python/site-packages')

import requests
from bs4 import BeautifulSoup
import urllib.parse
import argparse
import logging


parser = argparse.ArgumentParser()
parser.add_argument("-p", "--page", type=str, default="Erdős number")
parser.add_argument("-d", "--depth", type=int, default=3)
args = parser.parse_args()

def recursive_scrapper(wikilink, links_counter, depth, parse_links=False):
    if depth >= 0:
        headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.102 Safari/537.36'}
        wikilink = "https://en.wikipedia.org/wiki/" + wikilink.replace(" ", "_")
        logging.info(wikilink)
        pairs_list = []
        r = requests.get(wikilink, headers=headers)
        if r.status_code == 200:
            soup = BeautifulSoup(r.content, "html.parser")
            head = soup.find("h1", class_="firstHeading mw-first-heading")
            body = soup.find("div", class_="mw-content-ltr mw-parser-output")
            if parse_links == False:
                ex_span = body.find("span", id="External_links")
                if ex_span != None:
                    ex_links = ex_span.parent
                    ddd = ex_links.find_next_sibling()
                    while ddd != None:
                        ddd.extract()
                        ddd = ex_links.find_next_sibling()
            for a_hrefs in body.find_all("a", href=True):
                if links_counter >= 1000:
                    break
                if re.match(r"^/wiki/*", a_hrefs["href"]) and (
                    a_hrefs["href"].find(":") == -1 or a_hrefs["href"].find(":_") != -1
                ):
                    links_counter += 1
                    ref_page_head = a_hrefs["href"].split("/wiki/")
                    page_head = wikilink.split("/wiki/")
                    ref_page_head[1] = urllib.parse.unquote(
                        ref_page_head[1], encoding="utf-8", errors="replace"
                    )
                    page_head[1] = urllib.parse.unquote(
                        page_head[1], encoding="utf-8", errors="replace"
                    )
                    pair = {
                        "from": wikilink,
                        "to": "https://en.wikipedia.org" + a_hrefs["href"],
                        "name": page_head[1],
                        "ref_name": ref_page_head[1],
                    }
                    pairs_list.append(pair)
            if os.path.exists("wiki.json"):
                temp = []
                with open("wiki.json", "r") as f:
                    temp = json.loads(f.read()) + pairs_list
                with open("wiki.json", "w") as f:
                    json.dump(temp, f, indent=4)
            else:
                with open("wiki.json", "w") as f:
                    json.dump(pairs_list, f, indent=4)
            for dictionary in pairs_list:
                val = list(dictionary.values())
                if links_counter >= 1000:
                    break
                links_counter = recursive_scrapper(val[3], links_counter, depth - 1)
        else:
            print("Страница не вернула данных")
    return links_counter
    
#recursive_scrapper(args.page, 0, args.depth, False)
