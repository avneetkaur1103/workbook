""" Given a Binary Tree having positive and negative nodes, the task is to find maximum sum level in it. """
from queue import Queue

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def max_level_sum(root):
	max_sum = 0
	if root:
		q = Queue()
		q.put(root)
		while q.qsize():
			count = q.qsize()
			sum = 0
			for _ in range(count):
				root = q.get()
				sum += root.key
				q.put(root.left) if root.left else None
				q.put(root.right) if root.right else None
			max_sum = sum if sum > max_sum else max_sum
	return max_sum

if __name__ == '__main__':
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)
	root.right.right = Node(8)
	root.right.right.left = Node(6)
	root.right.right.right = Node(7)
	print('Max level sum: ', max_level_sum(root))
