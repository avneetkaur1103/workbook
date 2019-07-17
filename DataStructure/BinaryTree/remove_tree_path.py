""" Given a binary tree, a complete path is defined as a path from root to a leaf. The sum of all nodes on that path is defined as the sum of that path.
 Given a number K, you have to remove (prune the tree) all nodes which don’t lie in any path with sum>=k. """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def inorder(root):
	if root:
		inorder(root.left)
		print(root.key, end=' ')
		inorder(root.right)

def prune_tree(root, k, sum=0):
	if not root:
		return tuple([sum,None])

	sum += root.key
	lsum, root.left = prune_tree(root.left,k,sum)
	rsum, root.right = prune_tree(root.right,k,sum)

	if max(lsum,rsum) >= k:
		return max(lsum,rsum), root
	else:
		return max(lsum,rsum), None

# Driver Code 
if __name__ == '__main__': 
	k = 45
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)
	root.right.left = Node(6)
	root.right.right = Node(7)
	root.left.left.left = Node(8)
	root.left.left.right = Node(9)
	root.left.right.left = Node(12)
	root.right.right.left = Node(10)
	root.right.right.left.right = Node(11)
	root.left.left.right.left = Node(13)
	root.left.left.right.right = Node(14)
	root.left.left.right.right.left = Node(15)
  
	print("Tree before truncation")
	inorder(root)
	_,root = prune_tree(root, k) # k is 45
	print("\nTree after truncation")
	inorder(root)

