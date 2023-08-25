#!/usr/bin/env python3

from dataclasses import dataclass
import sys

# Classes

'''
class Node(object):
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left  = left
        self.right = right

    def __str__(self):
        return f'Node({self.value},{self.left},{self.right})'
'''

@dataclass
class Node:
    value:  int
    left:   'Node' = None
    right:  'Node' = None

class Tree:
    def __init__(self):
        self.root = None

    def search(self, value):                # Discuss: Search
        return self._search(self.root, value)

    def _search(self, node, value):        # Discuss: Recursive helper
        if node is None:
            return False

        if value == node.value:
            return True

        if value <= node.value:
            return self._search(node.left, value)
        else:
            return self._search(node.right, value)

    def insert(self, value):                # Discuss: Insertion
        self.root = self._insert(self.root, value)

    def _insert(self, node, value):
        if node is None:
            return Node(value)

        if value <= node.value:
            node.left  = self._insert(node.left, value)
        else:
            node.right = self._insert(node.right, value)

        return node

    def print(self):                        # Discuss: Traversal
        self._print(self.root)

    def _print(self, node):                # Discuss: In-Order Traversal
        if not node:
            return

        self._print(node.left)
        print(node.value)
        self._print(node.right)

    def nodes(self):                        # Review: Generators
        yield from self._nodes(self.root)

    def _nodes(self, node):
        if node:
            yield from self._nodes(node.left)
            yield node.value
            yield from self._nodes(node.right)

# Main Execution

def main():
    tree = Tree()
    for number in map(int, sys.argv[1:]):
        tree.insert(number)

    for number in map(int, sys.argv[1:]):
        print(number, tree.search(number))
        print(2*number, tree.search(number*2))

    tree.print()
    print(', '.join(map(str, tree.nodes())))

if __name__ == '__main__':
    main()
