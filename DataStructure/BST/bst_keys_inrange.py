""" Count BST nodes that lie in a given range. """
class Node:
	def __init__(self, key):
		self.key = key
		self.left = self.right = None

def keys_in_range(root, min, max):
	if not root:
		return 0

	total= 0
	if not root.key < min:
		total += keys_in_range(root.left, min, max)

	if min <= root.key <= max:
		print(root.key, end=' ')
		total += 1

	if not root.key > max:
		total += keys_in_range(root.right, min, max)

	return total

# Driver Code 
if __name__ == '__main__': 
      
    # Let us construct the BST shown in  
    # the above figure  
    root = Node(10)  
    root.left = Node(5)  
    root.right = Node(50)  
    root.left.left = Node(1)  
    root.right.left = Node(40) 
    root.right.right = Node(100) 
    print('\ncount = ', keys_in_range(root, 5, 45))

