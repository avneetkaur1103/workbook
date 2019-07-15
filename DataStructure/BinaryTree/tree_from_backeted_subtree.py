""" 4(2(3)(1))(6(5)) first character in string is root.
	 Substring inside the first adjacent pair of parenthesis is for left subtree and substring inside second pair of parenthesis is for right subtree """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def preorder(root):
	if root:
		print(root.key, end=' ')
		preorder(root.left)
		preorder(root.right)

def extract(input):
	left = list()
	right = list()

	count = 0
	dissection_index = -1
	for i,value in enumerate(input):
		if value == '(':
			count += 1
		if value == ')':
			count -= 1
			if not count:
				dissection_index = i
				break
	if not dissection_index == -1:
		left = input[1:dissection_index]
		right = input[dissection_index+2:] if dissection_index+2 < len(input) else []

	return left, right


def build_tree(input):
	root = None
	if input:
		root = Node(input.pop(0))
		left, right = extract(input) if input else (None, None)
		root.left = build_tree(left)
		root.right = build_tree(right)
	return root

# Driver Code  
if __name__ == '__main__': 
	Str = list("4(2(3)(1))(6(5))")
	root = build_tree(Str)
	preorder(root)

