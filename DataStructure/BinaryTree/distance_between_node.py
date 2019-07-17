""" Find the distance between two keys in a binary tree, no parent pointers are given. """
class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def find_level(root, child, level=0):
	if not root:
		return False, 0

	if root.key == child:
		return True, level

	in_left, level = find_level(root.left, child, level+1)
	if in_left:
		return True, level
	in_right, level = find_level(root.right, child, level+1)
	if in_right:
		return True, level 

	return False, 0  # level only needs to be forwarded

def find_lca_util(root, n1, n2):
	if not root:
		return None

	if root.key == n1:
		find_lca_util.bool1 = True
		return root

	if root.key == n2:
		find_lca_util.bool2 = True
		return root
	left = find_lca_util(root.left, n1, n2)
	right = find_lca_util(root.right, n1, n2)
	if left and right:
		return root

	return left if left else right # forwarding

def find_lca(root, n1, n2):
	find_lca_util.bool1 = find_lca_util.bool2 = False
	lca = find_lca_util(root,n1,n2)
	if find_lca_util.bool1 and find_lca_util.bool2:
		return lca
	if find_level(lca, n2)[0] if find_lca_util.bool1 else find_level(lca, n2)[0]:
		return lca
	return None

def distance(root, n1, n2):
	lca = find_lca(root, n1, n2)
	if lca:
		d1 = find_level(lca, n1)[1]
		d2 = find_level(lca, n2)[1]
		return d1 + d2
	raise Exception('Keys not found')

if __name__ == '__main__':
	# Driver program to test above function
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)
	root.right.left = Node(6)
	root.right.right = Node(7)
	root.right.left.right = Node(8)

	print("Dist(4,5) = ", distance(root, 4, 5))
	print("Dist(4,6) = ", distance(root, 4, 6))
	print("Dist(3,4) = ", distance(root, 3, 4))
	print("Dist(2,4) = ", distance(root, 2, 4))
	print("Dist(8,5) = ", distance(root, 8, 5))
