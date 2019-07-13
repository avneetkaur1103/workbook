""" Boundary Traversal of a tree """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def print_leaves(root):
	if root:
		print_leaves(root.left)
		if not root.left and not root.right:
			print(root.key, end=' ')
		print_leaves(root.right)

def print_left_view(root):
	if root:
		if root.left:
			print(root.key, end=' ')
			print_left_view(root.left)
		elif root.right:
			print(root.key, end=' ')
			print_left_view(root.right)

def print_right_view(root):
	if root:
		if root.right:
			print(root.key, end=' ')
			print_left_view(root.right)
		elif root.left:
			print(root.key, end=' ')
			print_left_view(root.left)

def print_boundary(root):
	if root:
		print(root.key, end=' ')
		print_left_view(root.left)
		print_leaves(root.left)
		print_leaves(root.right)
		print_right_view(root.right)

if __name__ == '__main__':
	root = Node(20) 
	root.left = Node(8) 
	root.left.left = Node(4) 
	root.left.right = Node(12) 
	root.left.right.left = Node(10) 
	root.left.right.right = Node(14) 
	root.right = Node(22) 
	root.right.right = Node(25) 
	print_boundary(root) 
