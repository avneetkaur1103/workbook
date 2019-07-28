""" Lowest Common ancestor in BST. """
class Node:
	def __init__(self, key):
		self.key = key
		self.left = self.right = None

def lca(root, n1, n2):
	if not root:
		return None

	if root.key > n1 and root.key > n2:
		return lca(root.left, n1, n2)
	if root.key < n1 and root.key < n2:
		return lca(root.right, n1, n2)

	return root

if __name__ == '__main__':
	# Driver program to test above function 
	root = Node(20)
	root.left = Node(8)
	root.right = Node(22)
	root.left.left = Node(4)
	root.left.right = Node(12)
	root.left.right.left = Node(10)
	root.left.right.right = Node(14)
	  
	n1 = 10 ; n2 = 14
	print('Lca: ', lca(root, n1, n2).key)