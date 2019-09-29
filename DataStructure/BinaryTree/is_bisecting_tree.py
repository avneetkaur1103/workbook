""" Given a Binary Tree, find if there exist edge whose removal creates two trees of equal size[in terms of no of nodes] """
class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def preorder(root):
	if root:
		print(root.key, end=' ')
		preorder(root.left)
		preorder(root.right)

def size(root):
	if not root:
		return 0
	return 1 + size(root.left) + size(root.right)

def is_bisecting_tree_util(root, n):
	if not root:
		return 0, False

	is_left_bisecting, left_size  = is_bisecting_tree_util(root.left,n)
	is_right_bisecting, right_size  = is_bisecting_tree_util(root.left,n)

	if n/2 == 1+left_size + right_size or (is_left_bisecting or is_right_bisecting):  # same as looking for duplicate subtree
		return True, 1+left_size + right_size
	return False, 1+left_size + right_size

def is_bisecting_tree(root):
	n = size(root)
	result, _ = is_bisecting_tree_util(root, n)
	return result

if __name__ == '__main__':
    """ Let us con below tree  
                  1  
                / 	\  
                2 	3  
               / \	 \  
              4   5   6 """
    root = Node(1)
    root.left = Node(2) 
    root.right = Node(3)
    root.left.left = Node(4) 
    root.left.right = Node(5) 
    root.right.right = Node(6)
    print('And = ', is_bisecting_tree(root))