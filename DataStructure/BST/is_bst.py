""" A program to check if a binary tree is BST or not """

class Node:
	def __init__(self, key):
		self.key = key
		self.left = self.right = None

def is_bst(root, min, max):
	if not root:
		return True

	left = is_bst(root.left, min, root.key)
	right = is_bst(root.right, root.key, max)

	if min < root.key < max and left and right:
		return True

if __name__ == '__main__':
	# Driver program to test above function 
	root = Node(4)
	root.left = Node(2)
	root.right = Node(5)
	root.left.left = Node(1)
	root.left.right = Node(3)
	print('Is BST: ', is_bst(root, float('-inf'), float('inf')))
