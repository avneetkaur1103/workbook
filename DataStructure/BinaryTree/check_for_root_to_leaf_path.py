""" Given a binary tree and an array, the task is to find if the given array sequence is present as a root to leaf path in given tree. """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def check_path(root, arr):
	if not root:
		return not arr

	if root.key == arr[0]:
		arr.pop(0)
		if not arr and not(root.left or root.right):
			return True
		return check_path(root.left, arr) or check_path(root.right, arr)
	return False

# Driver Code 
if __name__ == '__main__': 
      
    # arr[] -. sequence of root to leaf path  
    arr = [5, 8, 6, 7]   
    root = Node(5)  
    root.left = Node(3)  
    root.right = Node(8)  
    root.left.left = Node(2)  
    root.left.right = Node(4)  
    root.left.left.left = Node(1)  
    root.right.left = Node(6)  
    root.right.left.right = Node(7)
    print("Path Exists") if check_path(root, arr) else print("Path does not Exist")

