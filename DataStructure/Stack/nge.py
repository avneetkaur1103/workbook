''' Scan left to right, push it onto stack, wait for nge.
	As we face it pop all smaller element and assign the 
	current element as nge of all poped element.
'''

def nge(input):
	if not len(input):
		return None

	stack = list()
	result = [None] * len(input)

	for index,element in enumerate(input):
		while stack and input[stack[-1]] < element:
			result[stack.pop()] = element
		stack.append(index)


	while stack:
		result[stack.pop()] = -1

	return result

if __name__ == '__main__':
	input = [11, 13, 21, 3]
	print('Ans = ' + str(nge(input)))

