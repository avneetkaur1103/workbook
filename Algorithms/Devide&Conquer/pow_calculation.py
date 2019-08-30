""" Given two integers x and n, write a function to compute xn. We may assume that x and n are small and overflow doesn’t happen. """
def pow(x, n):
	if n == 0:
		return 1
	res = pow(x, n//2)
	if n & 1:
		return x * res * res
	else:
		return res *res

if __name__ == '__main__':
	x = 2; n = 9
	print(f'{x}^{n}: ', pow(x,n))