""" Ugly numbers are numbers whose only prime factors are 2, 3 or 5. """

def ugly_no(n):
	uglies = [1]
	i2 = i3 = i5 = 0
	next_multiple_2 = 2
	next_multiple_3 = 3
	next_multiple_5 = 5

	for i in range(1, n):
		next_ugly_no = min(next_multiple_2, next_multiple_3, next_multiple_5)
		uglies.append(next_ugly_no)
		if next_ugly_no == next_multiple_2:
			i2 += 1
			next_multiple_2 = uglies[i2]*2
		if next_ugly_no == next_multiple_3:
			i3 += 1
			next_multiple_3 = uglies[i3]*3
		if next_ugly_no == next_multiple_5:
			i5 += 1
			next_multiple_5 = uglies[i5]*5
	return uglies[-1]

if __name__ == '__main__':
	x = 150
	print(f'{x}th ugly no ', ugly_no(x))

