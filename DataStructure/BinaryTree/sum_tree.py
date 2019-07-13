""" Given a binary tree containing n nodes.
 	The problem is to replace each node in the binary tree with the sum of its inorder predecessor and inorder successor. 
"""
class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def store_inorder(root, arr):
	if root:
		store_inorder(root.left, arr)
		arr.append(root.key)
		store_inorder(root.right, arr)

def replace_inorder_util(root, arr):
	if root:
		replace_inorder_util(root.left, arr)
		root.key = arr[0] + arr[2]
		arr.pop(0)
		replace_inorder_util(root.right, arr)

def replace_inorder(root):
	arr = [0]
	store_inorder(root, arr)
	arr.append(0)
	replace_inorder_util(root, arr)

def preorder(root):
	if root:
		print(root.key, end=" ")
		preorder(root.left)
		preorder(root.right)

if __name__ == '__main__':
	root = Node(1)  # 1
	root.left = Node(2)  # / \
	root.right = Node(3)  # 2	3
	root.left.left = Node(4)  # / \ / \
	root.left.right = Node(5)  # 4 5 6 7
	root.right.left = Node(6)
	root.right.right = Node(7)

	print('Before: ')
	preorder(root)
	replace_inorder(root)
	print('After: ')
	preorder(root)
