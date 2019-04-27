#from __future__ import print_function
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

	def find_loop(self):
		slow = fast = self.head
		while slow and fast and fast.next:
			slow = slow.next
			fast = fast.next.next
			if slow == fast:
				self.remove_loop(slow)
				return True

		return False

	def remove_loop(self,ptr):
		slow = self.head
		fast = ptr
		while not slow.next == fast.next:
			slow = slow.next
			fast = fast.next

		fast.next = None

	def create_loop(self):
		node = self.head
		ptr = self.head
		while node.next:
			choice = random.choice([True, False])
			if choice:
				ptr = node
			node = node.next
		print('Debug: looping at {}'.format(ptr.data))
		node.next = ptr




if __name__ == '__main__':
	ll = LinkedList()
	for x in range(1,10):
		ll.push(x)
	ll.printll()
	ll.create_loop()
	ll.printll()
	result = ll.find_loop()
	print('result {}'.format(result))
	ll.printll()


