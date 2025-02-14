import math

G = {
    'A': {'B': 3, 'C': 1},
    'B': {'A': 3, 'C': 7, 'D': 5, 'E': 1},
    'C': {'A': 1, 'B': 7, 'D': 2},
    'D': {'C': 2, 'B': 5, 'E': 7},
    'E': {'B': 1, 'D': 7}
}

def initialize_mst(start):
    tree = set([start])
    edges = []
    return tree, edges

def find_min_edge(G, tree):
    min_edge = None
    min_weight = math.inf
    for u in tree:
        for v, weight in G[u].items():
            if v not in tree and weight < min_weight:
                min_weight = weight
                min_edge = (u, v, weight)
    return min_edge

def prim_algorithm(G, start):
    tree, edges = initialize_mst(start)
    while len(tree) < len(G):
        edge = find_min_edge(G, tree)
        if edge:
            u, v, weight = edge
            tree.add(v)
            edges.append((u, v, weight))
    return edges

def display_mst(edges):
    total_cost = sum(weight for _, _, weight in edges)
    for u, v, weight in edges:
        print(f'{u} -> {v} with cost {weight}')
    print(f'Total cost of MST: {total_cost}')

start = 'A'
edges = prim_algorithm(G, start)
display_mst(edges)
