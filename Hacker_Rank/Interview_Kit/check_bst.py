""" Node is defined as
class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
"""
def check_bst_util(root, _min, _max):
	if not root:
		return True
	if _min < root.data < _max:
		return check_bst_util(root.left, _min, root.data) and check_bst_util(root.right, root.data, _max)

	return False

def checkBST(root):
    return check_bst_util(root, float('-inf'), float('inf'))