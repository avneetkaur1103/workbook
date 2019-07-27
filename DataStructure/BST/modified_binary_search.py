""" Largest number in BST which is less than or equal to N """

class Node:
	def __init__(self,key):
		self.key = key
		self.left = self.right = None

# To insert a new node in BST  
def insert(node, key): 
      
    # if tree is empty return new node  
    if node == None:  
        return Node(key) 
  
    # if key is less then or grater then  
    # node value then recur down the tree  
    if key < node.key:  
        node.left = insert(node.left, key)  
    elif key > node.key:  
        node.right = insert(node.right, key) 
          
    # return the (unchanged) node pointer  
    return node

def search(root, key):
	if not root:
		return None

	if root.key == key:
		return key
	if root.key < key:
		result = search(root.right, key)
		return result if result else root.key
	if root.key > key:
		return search(root.left,key)

# Driver code  
if __name__ == '__main__': 
    N = 24
  
    # creating following BST  
    #  
    #             5  
    #         / \  
    #         2     12  
    #     / \ / \  
    #     1 3 9 21  
    #                 / \  
    #             19 25  
    root = None
    root = insert(root, 25) 
    insert(root, 2)  
    insert(root, 1)  
    insert(root, 3)  
    insert(root, 12)  
    insert(root, 9)  
    insert(root, 21)  
    insert(root, 19)  
    insert(root, 25)
    findMaxforN = search
    print(findMaxforN(root, N)) 