""" Check if BST is a heap = max heap """
class Node:
	def __init__(self, key):
		self.key = key
		self.left = self.right = None

def is_complete(root, index, size):
	if not root:
		return True

	if index >= size:
		return False

	return is_complete(root.left, 2*index + 1, size) and is_complete(root.right, 2*index + 2, size)

def holds_heap_invariant(root):
	if not root:
		return True

	left = root.key > root.left.key if root.left else True
	right = root.key > root.right.key if root.right else True

	return left and right and holds_heap_invariant(root.left) and holds_heap_invariant(root.right)

def count_nodes(root): 
		if root is None:
			return 0
		return 1 + count_nodes(root.left) + count_nodes(root.right)

def is_heap(root):
	size = count_nodes(root)
	return is_complete(root, 0, size) and holds_heap_invariant(root)

if __name__ == '__main__':
	root = Node(5)
	root.left = Node(2) 
	root.right = Node(3) 
	root.left.right = Node(1)
	print('Is Heap: ', is_heap(root))