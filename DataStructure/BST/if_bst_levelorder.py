""" Check if the given array can represent Level Order Traversal of Binary Search Tree. """
from queue import Queue

class Node:
	def __init__(self, key, min=float('-inf'), max=float('inf')):
		self.key = key
		self.min = min
		self.max = max

def level_order_of_bst(levelorder):
	if not levelorder:
		return True

	q = Queue()
	q.put(Node(levelorder.pop(0)))

	while levelorder and q.qsize():
		parent = q.get()
		curr = levelorder[0]
		if parent.min < curr < parent.key:
			q.put(Node(curr, min = parent.min, max = parent.key))
			levelorder.pop(0)

		curr = levelorder[0]
		if parent.key < curr < parent.max:
			q.put(Node(curr, min = parent.key, max = parent.max))
			levelorder.pop(0)

	return False if levelorder else True

if __name__ == "__main__":  
  
	arr = [7, 4, 12, 3, 6, 8, 1, 5, 10]
	print('Is levelorder of bst: ', level_order_of_bst(arr))





