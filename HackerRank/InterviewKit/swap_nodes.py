#!/bin/python3

import os
import sys

#
# Complete the swapNodes function below.
#
class Node:
	def __init__(self, key):
		self.key = key
		self.left = None
		self.right = None

def build_tree(indexes, i):
	root = Node(i)
	root.left = build_tree(indexes, indexes[i - 1][0]) if not indexes[i - 1][0] == -1 else None
	root.right = build_tree(indexes, indexes[i - 1][1]) if not indexes[i - 1][1] == -1 else None
	return root

def build_tree_itr(indexes):
	n = len(indexes)

	nodes = [None] * n
	for i in range(n - 1, -1, -1):
		root = Node(i + 1)
		if not indexes[i][0] == -1 and nodes[indexes[i][0] - 1]:
			root.left = nodes[indexes[i][0] - 1]
		else:
			root.left = None
		if not indexes[i][1] == -1 and nodes[indexes[i][1] - 1]:
			root.right = nodes[indexes[i][1] - 1]
		else:
			root.right = None

		nodes[i] = root
	return nodes[0]

def swap_nodes(root, k, h):
	if not root:
		return root

	swap_nodes(root.left, k, h + 1)
	swap_nodes(root.right, k, h + 1)

	if h % k == 0:
		root.left, root.right = root.right, root.left

	return root

def inorder(root, result):
	if root:
		inorder(root.left, result)
		result.append(root.key)
		inorder(root.right, result)

def swapNodes(indexes, queries):
	root = build_tree_itr(indexes)
	result = list()
	for k in queries:
		root = swap_nodes(root, k, 1)
		res = list()
		inorder(root, res)
		result.append(res)
	return result

if __name__ == '__main__':
	result_path = os.path.join(os.getcwd(), 'result.txt')
	os.environ['OUTPUT_PATH'] = result_path

	fptr = open(os.environ['OUTPUT_PATH'], 'w')

	n = int(input())

	indexes = []

	for _ in range(n):
		indexes.append(list(map(int, input().rstrip().split())))

	queries_count = int(input())

	queries = []

	for _ in range(queries_count):
		queries_item = int(input())
		queries.append(queries_item)

	result = swapNodes(indexes, queries)

	fptr.write('\n'.join([' '.join(map(str, x)) for x in result]))
	fptr.write('\n')

	fptr.close()
