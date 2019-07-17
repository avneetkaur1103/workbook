""" Given a binary tree (not a binary search tree) and two values say n1 and n2, write a program to find the least common ancestor. """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

	def __str__(self):
		return str(self.key)

def check_node(root, child):
	if not root:
		return False

	if root.key == child or check_node(root.left, child) or check_node(root.right, child):
		return True

	return False

def lac_util(root, n1, n2):
	if not root:
		return None

	if root.key == n1: # Base case
		lac_util.bool1 = True
		return root

	if root.key == n2: # Base case
		lac_util.bool2 = True
		return root

	left = lac_util(root.left, n1, n2)
	right = lac_util(root.right, n1, n2)

	if left and right: # if both are found in different subtrees
		return root

	return left if left else right # considering keys are present

def find_lca(root, n1, n2):
	lac_util.bool1 = lac_util.bool2 = False  # needs reset for multiple iteration
	lca = lac_util(root, n1, n2)
	if lac_util.bool1 and lac_util.bool2:
		return lca
	if check_node(lca, n2) if lac_util.bool1 else check_node(lca, n2):
		return lca
	return None

def print_path_to_node(root, node):
	if root:
		if print_path_to_node(root.left,node) or print_path_to_node(root.right, node) or root.key == node.key:
			print(root.key, end=' ')
			return True
	return False

def print_common_path(root, n1, n2):
	lca = find_lca(root, n1, n2)
	if lca:
		print_path_to_node(root, lca)
	else:
		print('No common ancestor')

if __name__ == '__main__':
	root = Node(1) 
	root.left = Node(2) 
	root.right = Node(3) 
	root.left.left = Node(4) 
	root.left.right = Node(5) 
	root.right.left = Node(6) 
	root.right.right = Node(7)
	print("LCA = ", find_lca(root,4,5))
	# print("LCA = ", find_lca(root, 4, 10))
	print('Common ancestors: ')
	print_common_path(root,4,5)



