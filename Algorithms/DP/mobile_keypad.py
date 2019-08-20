""" Given the mobile numeric keypad. You can only press buttons that are up, left, right or down to the current button.
You are not allowed to press bottom row corner buttons. """
neighbours = {0:[0,8],
			  1:[1,2, 4],
			  2:[1,2,3,5],
			  3:[2,3,6],
			  4:[1,4,5,7],
			  5:[2,4,5,6,8],
			  6:[3,5,6,9],
			  7:[4,7,8],
			  8:[0,5,7,8,9],
			  9:[6,8,9]}

def count_numbers(n):
	prev = [1]*10
	curr = [0]*10
	for i in range(2,n+1):
		curr = [sum(prev[x] for x in vals) for key,vals in neighbours.items()]
		prev = curr
	return sum(curr)
if __name__ == '__main__':
	print(f'Count of len {5}', count_numbers(5))


