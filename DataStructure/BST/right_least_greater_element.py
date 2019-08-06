""" Given an array of integers, replace every element with the least greater element 
on its right side in the array. If there are no greater element on right side, replace it with -1. """

class Node:
	def __init__(self, key):
		self.key = key
		self.left = self.right = None

def insert(root, key):
	if not root:
		return Node(key), None

	if key < root.key:
		root.left, succ = insert(root.left, key)
		succ = root.key if not succ else succ
		return root, succ
	if key > root.key:
		root.right, succ = insert(root.right, key)
		return root, succ

def next_greater_on_right(arr):
	root = None
	result = list()
	for i in reversed(arr):
		root, succ = insert(root, i)
		result.append(succ) if succ else result.append(-1)

	return reversed(result)
		

if __name__ == '__main__':
	arr = [8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28]
	result = next_greater_on_right(arr)

	for i in result:
		print(i, end=' ')

