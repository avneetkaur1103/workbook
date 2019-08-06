""" Given a stream of integers, lookup the rank of a given integer x.
 Rank of an integer in stream is Total number of elements less than or equal to x (not including x) """


class Node:
	def __init__(self,key):
		self.key = key
		self.left = self.right = None
		self.left_size = 0

def insert(root, key):
	if not root:
		return Node(key)
	if root.key == key:
		root.left_size += 1
	elif key < root.key:
		root.left_size += 1
		root.left = insert(root.left, key)
	elif key > root.key:
		root.right = insert(root.right, key)
	return root

def get_rank(root, key):
	if root:
		if root.key == key:
			return root.left_size
		if root.key > key:
			return get_rank(root.left, key)
		if root.key < key:
			return 1 + root.left_size + get_rank(root.right, key)
	return 0

if __name__ == '__main__': 
	arr = [5, 1, 4, 4, 5, 9, 7, 13, 3]
	root = None
	for i in arr:
		root = insert(root, i)
	x = 4
	print("Rank of", x, "in stream is:",
					   get_rank(root, x))
	x = 13
	print("Rank of", x, "in stream is:",
					   get_rank(root, x))
