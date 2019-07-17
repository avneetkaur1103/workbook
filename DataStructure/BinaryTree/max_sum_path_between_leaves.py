""" Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.
The maximum sum path may or may not go through root. """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def max_sum_path_util(root):
	if not root:
		return 0, []

	left_sum, left_subtree_path = max_sum_path_util(root.left)
	right_sum, right_subtree_path = max_sum_path_util(root.right)

	if left_sum + right_sum + root.key > max_sum_path_util.max_sum:
		max_sum_path_util.max_sum = left_sum + right_sum + root.key
		max_sum_path_util.final_path.clear()
		max_sum_path_util.final_path += left_subtree_path + [root.key] + list(reversed(right_subtree_path))

	if left_sum > right_sum:
		return root.key+left_sum, left_subtree_path + [root.key]
	return root.key+right_sum, right_subtree_path + [root.key]

def max_sum_path(root):
	max_sum_path_util.max_sum = float('-inf')
	max_sum_path_util.final_path = list()
	max_sum_path_util(root)
	print('Path = ', max_sum_path_util.final_path, ' Sum: ', sum(max_sum_path_util.final_path))

if __name__ == '__main__':
	# Enter the binary tree ... 
	#           1
	#         /   \
	#        2     3
	#      /   \
	#     4     5
	#      \   / \
	#       8 6   7
	#      /
	#     9

	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)
	root.left.right.left = Node(6)
	root.left.right.right = Node(7)
	root.left.left.right = Node(8)
	root.left.left.right.left = Node(9)
	max_sum_path(root)

	print('Test 2:')
	# Driver program to test above function 
	root = Node(-15) 
	root.left = Node(5) 
	root.right = Node(6) 
	root.left.left = Node(-8) 
	root.left.right = Node(1) 
	root.left.left.left = Node(2) 
	root.left.left.right = Node(6) 
	root.right.left = Node(3) 
	root.right.right = Node(9) 
	root.right.right.right= Node(0) 
	root.right.right.right.left = Node(4) 
	root.right.right.right.right = Node(-1) 
	root.right.right.right.right.left = Node(10)
	max_sum_path(root)
