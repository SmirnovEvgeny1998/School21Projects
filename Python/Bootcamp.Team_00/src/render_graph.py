import os
from itertools import chain
import pandas as pd
import networkx as nx
import altair as alt
import cache_wiki


def graph_renderer(file_name, depth):

    with open("wiki.json", "r") as f:
        links_list = pd.read_json(file_name)

        relationships = (
            links_list.groupby(["name", "ref_name"])
            .size()
            .reset_index()
            .rename(columns={0: "size"})
        )
        G = nx.from_pandas_edgelist(
            relationships, "name", "ref_name", create_using=nx.Graph()
        )

    for rank in range(0, depth):
        nodes_in_rank = nx.descendants_at_distance(G, links_list.loc[0]["name"], rank)
        for node in nodes_in_rank:
            G.nodes[node]["rank"] = rank
            G.nodes[node]["label"] = "hh"

    pos = nx.drawing.nx_agraph.graphviz_layout(G, prog="twopi")

    pos_df = pd.DataFrame.from_records(
        dict(node_id=k, x=x, y=y) for k, (x, y) in pos.items()
    )

    node_df = relationships.rename(columns={"ref_name": "node_id"})

    edge_data = (
        (
            dict(d, **{"edge_id": i, "end": "source", "node_id": s}),
            dict(d, **{"edge_id": i, "end": "target", "node_id": t}),
        )
        for i, (s, t, d) in enumerate(G.edges.data())
    )
    edge_df = pd.DataFrame.from_records(chain.from_iterable(edge_data))

    x, y = alt.X("x:Q", axis=None), alt.Y("y:Q", axis=None)

    node_position_lookup = {
        "lookup": "node_id",
        "from_": alt.LookupData(data=pos_df, key="node_id", fields=["x", "y"]),
    }
    nodes = (
        alt.Chart(node_df)
        .mark_circle(
            opacity=1,
        )
        .encode(
            x=x,
            y=y,
            color=alt.Color("rank:N", legend=None),
            size=alt.Size("size", scale=alt.Scale(range=[100, 1000])),
        )
        .transform_lookup(**node_position_lookup)
    )
    edges = (
        alt.Chart(edge_df)
        .mark_line(color="gray")
        .encode(x=x, y=y, detail="edge_id:N")
        .transform_lookup(**node_position_lookup)
    )
    text = edges.mark_text(align="center", baseline="middle", color="black").encode(
        text="node_id"
    )
    chart = (
        (edges + nodes + text)
        .properties(
            width=1920,
            height=1080,
        )
        .configure_view(strokeWidth=0)
    )

    chart.save("chart.png")
    chart.interactive().save("chart.html")

    return


if __name__ == "__main__":
    if os.path.exists("wiki.json"):
        os.remove("wiki.json")
    links = 0
    depth = 1
    print(
        cache_wiki.recursive_scrapper(
            "Kang_Chun-hyok",
            links,
            depth,
        )
    )
    graph_renderer("wiki.json", depth)
