""" Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line. """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def print_diagonal_util(root, map, distance):
	if root:
		map[distance].append(root.key)
		print_diagonal_util(root.left, map, distance+1)
		print_diagonal_util(root.right,map, distance)

def print_diagonal(root):
	from collections import defaultdict
	d = defaultdict(list)
	print_diagonal_util(root, d, 0)

	for key, value in d.items():
		print('Level ', key, ' list ', value )

if __name__ == '__main__':
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(7)
	root.left.right = Node(6)
	root.right.left = Node(5)
	root.right.right = Node(4)
	print_diagonal(root)