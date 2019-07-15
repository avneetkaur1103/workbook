""" Given two binary trees, check if the first tree is subtree of the second one. """
class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def preorder(root):
	po = ""
	if root:
		po += str(root.key)
		po += preorder(root.left)
		po += preorder(root.right)
	return po

def inorder(root):
	io = ""
	if root:
		io += inorder(root.left)
		io += str(root.key)
		io += inorder(root.right)
	return io

def check_subtree(tree, subtree):
	subtree_po = preorder(subtree)
	subtree_io = inorder(subtree)

	tree_po = preorder(tree)
	tree_io = inorder(tree)

	if subtree_po in tree_po and subtree_io in tree_io:
		return True

	return False

def is_identical(root1, root2):
	if not root1 and not root2:
		return True
	if not (root1 and root2):
		return False
	if root1 and root2:
		return root1.key == root2.key and is_identical(root1.left, root2.left) and is_identical(root1.right, root2.right)

def check_subtree_recursive(tree, subtree):
	if not subtree:
		return True
	if not tree:
		return False
	if is_identical(tree,subtree):
		return True
	return check_subtree_recursive(tree.left,subtree) or check_subtree_recursive(tree.right,subtree)

if __name__ == '__main__':

	""" TREE 1 
     Construct the following tree 
              26 
            /   \ 
          10     3 
        /    \     \ 
      4      6      3 
       \ 
        30 
    """
	T = Node(26) 
	T.right = Node(3) 
	T.right.right  = Node(3) 
	T.left = Node(10) 
	T.left.left = Node(4) 
	T.left.left.right = Node(30) 
	T.left.right = Node(6) 
	  
	""" TREE 2 
	     Construct the following tree 
	          10 
	        /    \ 
	      4      6 
	       \ 
	        30 
	    """
	S = Node(10) 
	S.right = Node(6) 
	S.left = Node(4) 
	S.left.right = Node(30)
	print('Ans = ', check_subtree_recursive(T,S))