""" Given a binary tree and a node, print all cousins of given node. Note that siblings should not be printed. """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def get_level(root,key,level):
	if not root:
		return 0
	if root.key == key:
		return level

	level_from_left = get_level(root.left, key, level+1)
	if level_from_left:
		return level_from_left
	level_from_right = get_level(root.right, key, level+1)
	return level_from_right

def print_level(root, node, level):
	if root:
		if level < 2:
			return # node is at root means no cousin or sibling
		if level == 2:
			if root.left == node or root.right == node:
				return
			print(root.left.key, end=' ') if root.left else None
			print(root.right.key, end=' ') if root.right else None
		if level > 2:
			print_level(root.left, node, level-1)
			print_level(root.right, node, level-1)

def print_cousins(root, node):
	level = get_level(root,node.key,1)
	print_level(root,node,level)

# Driver Code 
if __name__ == '__main__': 
    root = Node(1)  
    root.left = Node(2)  
    root.right = Node(3)  
    root.left.left = Node(4)  
    root.left.right = Node(5)  
    root.left.right.right = Node(15)  
    root.right.left = Node(6)  
    root.right.right = Node(7)  
    root.right.left.right = Node(8)  
  
    print_cousins(root, root.left.right)



