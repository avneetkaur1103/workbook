from __future__ import print_function
import random
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
		count = 0
		while node:
			if count > 25:
				break
			print(node.data, end='->')
			node = node.next
			count += 1
		print('X')

	def nth_from_last(self, head, n):
		if head is None:
			return 0;
		val = self.nth_from_last(head.next,n) + 1
		if val == n:
			print('The nth from last is {}'.format(head.data))

		return val


if __name__ == '__main__':
	ll = LinkedList()
	for x in range(1,10):
		ll.push(x)
	ll.printll()
	ll.nth_from_last(ll.head, 10)




