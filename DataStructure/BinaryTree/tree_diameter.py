""" Print the longest leaf to leaf path in a Binary tree. """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def diameter_util(root):
	if not root:
		return 0, []

	left_height, left_subtree_path = diameter_util(root.left)
	right_height, right_subtree_path = diameter_util(root.right)

	if left_height + right_height + 1 > diameter_util.max_width:
		diameter_util.max_width = left_height + right_height + 1
		diameter_util.final_path.clear()
		diameter_util.final_path += left_subtree_path + [root.key] + list(reversed(right_subtree_path))

	if left_height > right_height:
		return 1+left_height, left_subtree_path + [root.key]
	return 1+right_height, right_subtree_path + [root.key]

diameter_util.max_width = float('-inf')
diameter_util.final_path = list()


def diameter(root):
	diameter_util(root)
	print('Ans = ', diameter_util.final_path)

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
	diameter(root)