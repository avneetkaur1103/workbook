""" Given a tree and a node data, your task to reverse the path till that particular Node. """

class Node(object):
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def reverse_path(root, data, arr):
	if not root:
		return None

	if root.key == data:
		arr.append(root.key)
		root.key = arr.pop(0)
		return root

	arr.append(root.key)
	left = right = None
	left = reverse_path(root.left, data, arr)
	if not left:
		right = reverse_path(root.right, data, arr)

	if left or right:
		root.key = arr.pop(0)
		return left if left else right
	else:
		arr.pop()
	return None

def inorder(root):
	if root:
		inorder(root.left)
		print(root.key, end=' ')
		inorder(root.right)

if __name__ == '__main__':
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(7)
	root.left.right = Node(6)
	root.right.left = Node(5)
	root.right.right = Node(4)
	print('Before ')
	inorder(root)
	arr = list()
	reverse_path(root, 7, arr)
	print('\nAfter ')
	inorder(root)



