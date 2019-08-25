""" n a daily share trading, a buyer buys shares in the morning and sells it on the same day.
 If the trader is allowed to make at most 2 transactions in a day,
  whereas the second transaction can only start after the first one is complete (Buy->sell->buy->sell).
 Given stock prices throughout the day, find out the maximum profit that a share trader could have made."""

def max_profit(price):
	n = len(price)
	profit = [0] * n

	max_selling_price = price[n-1]

	for i in range(n-2, -1, -1):
		if price[i] > max_selling_price:
			max_selling_price = price[i]
		profit[i] = max(profit[i+1], max_selling_price-price[i])

	min_buying_price = price[0]

	for i in range(1, n):
		if price[i] < min_buying_price:
			min_buying_price = price
		profit[i] = max(profit[i-1], profit[i] + price[i] - min_buying_price)

	return profit[-1]

if __name__ == '__main__':
	# Driver function 
	price = [2, 30, 15, 10, 8, 25, 80]
	print('Max Profit: ', max_profit(price))