def binary_search(data, value):
	first_index, last_index = 0, len(data)-1

	def search(a, b):
		if a > b:
			return None

		m = (a+b)/2 + (a+b)%2

		if data[m] == value:
			return m

		if data[m] < value:
			return search(m+1, b)
		else:
			return search(a, m-1)

	pos = search(first_index, last_index)
	return -1 if pos is None else pos+1