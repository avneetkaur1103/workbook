""" Given a binary tree and a node, we need to write a program to find inorder successor of this node. """

class Node(object):
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def leftmost(node):
	while node and node.left:
		node = node.left
	return node

def rightmost(node):
	while node and node.right:
		node = node.right
	return node

def find_successor_above(root,node):
	if not root:
		return None
	temp = find_successor_above(root.left, node) if find_successor_above(root.left, node) else find_successor_above(root.right, node)
	if root == node or temp:
		if temp and root.left == temp:
			print('Successor = ', root.key)
			return None
		return root
	return None
		

def inorder_successor(root, node):
	if node.right:
		print('successor = ', leftmost(node.right).key)
		return

	if rightmost(root) == node:
		print('No successor')
	else:
		find_successor_above(root, node)

# Driver Code 
if __name__ == '__main__':  
  
    root = Node(1)  
    root.left = Node(2)  
    root.right = Node(3)  
    root.left.left = Node(4)  
    root.left.right = Node(5)  
    root.right.right = Node(6)  
  
    # Case 1  
    inorder_successor(root, root.right)  
  
    # case 2  
    inorder_successor(root, root.left.left) 
  
    # case 3  
    inorder_successor(root, root.right.right) 




