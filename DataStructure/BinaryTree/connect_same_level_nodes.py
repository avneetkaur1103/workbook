""" Connect nodes at same level using constant extra space """

class Node:
	def __init__(self, value):
		self.key = value
		self.left = self.right = None
		self.next_right = None

def get_net_right(root):
	root = root.next_right
	while root:
		if root.left:
			return root.left
		if root.right:
			return root.right
		root = root.next_right
	return None


def connect_nodes_recur(root):
	if not root:
		return None

	if root.left:
		if root.right:
			root.left.next_right = root.right
			root.right.next_right = get_net_right(root)
		else:
			root.left.next_right = get_net_right(root)
		connect_nodes_recur(root.left)

	elif root.right:
		root.right.next_right = get_net_right(root)
		connect_nodes_recur(root.right)
	else:
		connect_nodes_recur(get_net_right(root))
	
def connect_node(root):
	if root:
		root.next_right = None
		connect_nodes_recur(root)

from queue import Queue
def print_levels(root):
	q = Queue()
	q.put(root)
	count = q.qsize()

	while not q.empty():
		count = q.qsize()
		while count:
			temp = q.get()
			print('{}->{}'.format(temp.key, temp.next_right.key if temp.next_right else None), end='|')
			q.put(temp.left) if temp.left else None
			q.put(temp.right) if temp.right else None
			count -= 1
		print('')

# Driver Code
if __name__ == '__main__':
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)
	connect_node(root)
	print_levels(root)