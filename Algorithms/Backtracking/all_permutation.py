''' Write a program to print all permutations of a given string '''
def permutations(str, start, end):
	if start == end:
		print(''.join(str))

	for i in range(start, end):
		str[start], str[i] = str[i], str[start]
		permutations(str, start+1, end)
		str[start], str[i] = str[i], str[start]

if __name__ == '__main__':
	str = 'ABC'
	permutations(list(str), 0, len(str))