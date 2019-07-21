""" Given a Binary Tree, check whether the Binary tree contains a duplicate sub-tree of size 2 or more.
	Note : Two same leaf nodes are not considered as subtree size of a leaf node is one. """

MARKER = '$'

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def has_duplicate_subtree(root):
	hashed_str = MARKER
	if root:
		sub_in_left, left = has_duplicate_subtree(root.left)
		sub_in_right, right = has_duplicate_subtree(root.right) # travesing postorder to obtain all subtree
		if sub_in_left or sub_in_right:
			return True, left if sub_in_left else right
		hashed_str = root.key + left + right  # pre-order uniquely represent a full binary tree / can reconstruct tree / can be used in encoding
		if len(hashed_str) > 3:
			if hashed_str in has_duplicate_subtree.hash_set:
				return True, hashed_str
			has_duplicate_subtree.hash_set.add(hashed_str)
	return False, hashed_str

has_duplicate_subtree.hash_set = set()

if __name__ == '__main__':
	root = Node('A')
	root.left = Node('B')
	root.right = Node('C')
	root.left.left = Node('D')
	root.left.right = Node('E')
	root.right.right = Node('B')
	root.right.right.right = Node('E')
	root.right.right.left= Node('D')
	print('Contains duplicate subtree: ', has_duplicate_subtree(root))