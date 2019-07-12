""" Given an array that represents Inorder Traversal, find all possible Binary Trees with the given Inorder traversal and print their preorder traversals. """

class Node(object):
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def preorder(root):
	if root:
		print(root.key, end=' ')
		preorder(root.left)
		preorder(root.right)

def get_trees(input):
	result = list()

	if not input:
		result.append(None)
		return result

	for i in range(len(input)):
		ltree = get_trees(input[:i]) 
		rtree = get_trees(input[i+1:])

		root = Node(input[i])
		for l in ltree:
			for r in rtree:
				root.left = l
				root.right = r
				result.append(root)

	return result

if __name__ == '__main__':
	inp = [4 , 5, 7] 
	trees = get_trees(inp) 
	print("Preorder traversals of different possible Binary Trees are")
	for i in trees : 
	    preorder(i)
	    print('')




