""" Design a data structure to do reservations of future jobs on a single machine under following constraints.
1) Every job requires exactly k time units of the machine.
2) The machine can do only one job at a time. 
3) Time is part of the system. Future Jobs keep coming at different times. Reservation of a future job is done only if there is no existing reservation within k time frame (after and before)
4) Whenever a job finishes (or its reservation time plus k becomes equal to current time), it is removed from system."""

class Node:
	def __init__(self,key):
		self.key = key
		self.left = self.right = None

def insert(root, time, k=4):
	if not root:
		return Node(time)

	if time - k <= root.key <= time + k:
		print(f'Job @{time} conflicts with job @{root.key}')
		return root

	if time < root.key - k:
		root.left = insert(root.left, time, k)
	elif time > root.key + k:
		root.right = insert(root.right, time, k)
	return root

if __name__ == '__main__':
	root = None
	root = insert(root, 2)
	root = insert(root, 15)
	root = insert(root, 7)
	root = insert(root, 20)
	root = insert(root, 3)