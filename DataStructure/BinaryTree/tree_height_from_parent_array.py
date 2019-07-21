""" A given array represents a tree in such a way that the array value gives the parent node of that particular index.
 The value of the root node index would always be -1. Find the height of the tree. """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None

def fill_depth(parent, depths, i):
	if depths[i]:
		return

	if parent[i] == -1:
		depths[i] = 1
		return

	if not depths[parent[i]]:
		fill_depth(parent, depths, parent[i])

	depths[i] = depths[parent[i]] + 1

def height(parent):
	depths = [None] * len(parent)
	for i in range(len(parent)):
		fill_depth(parent, depths, i)
	print(depths)

	return max(depths)
if __name__ == '__main__':
	parent = [-1 , 0 , 0 , 1 , 1 , 3 , 5]
	print('Depth: ', height(parent))

