import argparse
import os
import json
import sys

WIKI_FILE = "wiki.json"

parser = argparse.ArgumentParser()
parser.add_argument("-f", "--From", "--keywordfrom", type=str, default="Welsh Corgi")
parser.add_argument("-t", "--To", type=str, default="David TC Davies")
parser.add_argument("--non-directed", action="store_true")
parser.add_argument("-v", "--visualize", action="store_true")
args = parser.parse_args()


def find_hrefs(From, To):
    from_found = False
    to_found = False
    with open(WIKI_FILE, "r") as f:
        wiki_info = json.loads(f.read())
        for page in wiki_info:
            if page["name"] == From or page["ref_name"] == From:
                from_found = True
            if page["name"] == To or page["ref_name"] == To:
                to_found = True
    if from_found == True and to_found == True:
        return True
    else:
        return False


def json_to_list():
    with open(WIKI_FILE, "r") as f:
        wiki_info = json.loads(f.read())
        return wiki_info


def create_graph(wiki_info):
    graph = {}
    for page in wiki_info:
        graph[page["name"]] = []
        graph[page["ref_name"]] = []
    for page in wiki_info:
        graph[page["name"]].append(page["ref_name"])
        if args.non_directed == True:
            graph[page["ref_name"]].append(page["name"])
    return graph


def BFS_SP(graph, start, goal):
    explored = []
    queue = [[start]]
    if start == goal:
        one = [start]
        return one
    while queue:
        path = queue.pop(0)
        node = path[-1]
        if node not in explored:
            neighbours = graph[node]
            for neighbour in neighbours:
                new_path = list(path)
                new_path.append(neighbour)
                queue.append(new_path)
                if neighbour == goal:
                    return new_path
            explored.append(node)
    return None


if os.path.exists(WIKI_FILE):
    From = args.From.replace(" ", "_")
    To = args.To.replace(" ", "_")
    if find_hrefs(From, To):
        graph = create_graph(json_to_list())
        fin = BFS_SP(graph, From, To)
        if fin != None:
            print(len(fin) - 1)
            if args.visualize == True:
                for item in fin:
                    print(item, end="")
                    if item != To:
                        print(" -> ", end="")
        else:
            print("Impossible path or link doesnt exist")
    else:
        print("Links not found in database")
else:
    print("Database not found")
