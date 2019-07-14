""" Given an array that represents a tree in such a way that array indexes are values in tree nodes and array values give the parent node of that particular index (or node).
 The value of the root node index would always be -1 as there is no parent for root.
 Construct the standard linked representation of given Binary Tree from this given representation 
"""

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def build_tree(key, nodes, parent):
	if nodes[key]:
		return
	root = nodes[key] = Node(key)

	if not parent[key] == -1:
		p = build_tree(parent[key], nodes, parent) if not nodes[parent[key]] else nodes[parent[key]]
		if not p.left:
			p.left = root
		else:
			p.right = root
	return root

def create_tree(parent):
	nodes = [None] * len(parent)

	for x in range(len(nodes)):
		build_tree(x, nodes, parent)

	return nodes[parent.index(-1)]

# Inorder traversal of tree
def inorder(root): 
	if root:
		inorder(root.left)
		print(root.key, end=' ')
		inorder(root.right)
  
# Driver Method 
if __name__ == '__main__':
	parent = [-1, 0, 0, 1, 1, 3, 5]
	root = create_tree(parent)
	print("Inorder Traversal of constructed tree")
	inorder(root)
