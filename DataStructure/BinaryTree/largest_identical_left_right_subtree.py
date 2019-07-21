""" Given a binary tree, find the largest subtree having identical left and right subtree. Expected complexity is O(n). """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def largest_identical_subtree(root):
	if not root:
		return 0, ''

	ls, left_str = largest_identical_subtree(root.left)
	rs, right_str = largest_identical_subtree(root.right)

	size = 1 + ls + rs
	string = str(root.key) + left_str + right_str  # preoredr identifies full tree uniquely

	if left_str == right_str and size > largest_identical_subtree.max_size:
		largest_identical_subtree.max_size = size
		largest_identical_subtree.max_node = root

	return size, string

largest_identical_subtree.max_node = None
largest_identical_subtree.max_size = float('-inf')

# Driver Code 
if __name__ == '__main__': 
      
    # Let us construct the following Tree  
    #        50  
    #        /   \  
    #        10  60  
    #    / \     / \  
    #    5 20 70 70  
    #            / \ / \  
    #            65 80 65 80  
    root = Node(50)  
    root.left = Node(10)  
    root.right = Node(60)  
    root.left.left = Node(5)  
    root.left.right = Node(20)  
    root.right.left = Node(70)  
    root.right.left.left = Node(65)  
    root.right.left.right = Node(80)  
    root.right.right = Node(70)  
    root.right.right.left = Node(65)  
    root.right.right.right = Node(80) 
    largest_identical_subtree(root)
    print('Max Node: ', largest_identical_subtree.max_node.key, ' Size: ', largest_identical_subtree.max_size)