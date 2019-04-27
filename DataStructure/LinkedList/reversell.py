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

	def reverse_util(self, rest, prev):
		if rest is None:
			self.head = prev
			return
		self.reverse_util(rest.next, rest)
		rest.next = prev

	def reverse(self):
		if self.head is None:
			return
		self.reverse_util(self.head, None)

	def reverse_itr(self):
		prev = None
		curr = self.head
		next = None

		while curr:
			next = curr.next
			curr.next = prev
			prev = curr
			curr = next

		self.head = prev

	def printll(self):
		node = self.head
		while node:
			print(node.data, end='->')
			node = node.next
		print('X')


if __name__ == '__main__':
	ll = LinkedList()
	for x in range(1,10):
		ll.push(x)

	ll.printll()
	ll.reverse_itr()
	ll.printll()
	ll.reverse()
	ll.printll()

