#!/usr/bin/env python3

# Exercise 19-B: Passcode Cracking

import collections
import sys

# Graph structure

Graph = collections.namedtuple('Graph', 'edges degrees')

# Read Graph

def read_graph():
    edges = collections.defaultdict(set)
    for line in sys.stdin:
        digits = list(map(int, line.strip()))

        edges[digits[0]].add(digits[1])
        edges[digits[1]].add(digits[2])

    degrees = collections.defaultdict(int)
    for s, ts in edges.items():
        degrees[s]
        for t in ts:
            degrees[t] += 1

    return Graph(edges, degrees)

# Topological Sort

def topological_sort(graph):
    frontier = [v for v, d in graph.degrees.items() if d == 0]
    visited  = []

    while frontier:
        vertex = frontier.pop()

        visited.append(vertex)

        for neighbor in graph.edges[vertex]:
            graph.degrees[neighbor] -= 1
            if graph.degrees[neighbor] == 0:
                frontier.append(neighbor)

    return visited

# Main Execution

def main():
    graph = read_graph()
    code  = topological_sort(graph)

    print(''.join(map(str, code)))

if __name__ == '__main__':
    main()
