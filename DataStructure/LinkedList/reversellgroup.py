from __future__ import print_function
class Node:

	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:

	def __init__(self):
		self.head = None

	def push(self, data):
		new_node = Node(data)
		new_node.next = self.head
		self.head = new_node

	def printll(self):
		node = self.head
		while node:
			print(node.data, end='->')
			node = node.next
		print('X')

	def reverse_groups(self, head, k):
		prev = None
		curr = head
		next = None
		count = 0
		while curr and count < k:
			next = curr.next
			curr.next = prev
			prev = curr
			curr = next
			count +=1
		if next is not None:
			head.next = self.reverse_groups(next,k)
		return prev




if __name__ == '__main__':
	ll = LinkedList()
	for x in range(1,10):
		ll.push(x)
	ll.head = ll.reverse_groups(ll.head,3)
	ll.printll()


