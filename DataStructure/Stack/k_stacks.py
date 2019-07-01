class KStacks:
	def __init__(self, k, n):
		self.n = n
		self.k = k

		self.arr = [None] * n
		self.top = [-1] * k
		self.next = [i+1 for i in range(n)]
		self.next[n-1] = -1
		self.free = 0

	def is_empty(self, k):
		return self.top[k] == -1

	def is_full(self):
		return self.free == -1


	def push(self, k, value):
		if self.is_full():
			raise Exception('Stack Full')

		index = self.free
		self.free = self.next[index]
		self.next[index] = self.top[k]
		self.top[k] = index
		self.arr[index] = value

	def pop(self, k):
		if self.is_empty(k):
			raise Exception('Empty Stack')

		index = self.top[k]
		self.top[k] = self.next[index]
		self.next[index] = self.free
		self.free = index
		return self.arr[index]

if __name__ == '__main__':
	# Create 3 stacks using an  
    # array of size 10. 
    kstacks = KStacks(3, 10) 
  
    # Push some items onto stack number 2. 
    kstacks.push(2, 15) 
    kstacks.push(2, 45) 
  
    # Push some items onto stack number 1. 
    kstacks.push(1, 17) 
    kstacks.push(1, 49) 
    kstacks.push(1, 39) 
  
    # Push some items onto stack number 0. 
    kstacks.push(0, 11) 
    kstacks.push(0, 9) 
    kstacks.push(0, 7) 
  
    print("Popped element from stack 2 is " + 
                         str(kstacks.pop(2))) 
    print("Popped element from stack 1 is " + 
                         str(kstacks.pop(1))) 
    print("Popped element from stack 0 is " + 
                         str(kstacks.pop(0)))

