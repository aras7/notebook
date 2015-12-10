class DisjoinSet(object):
	"""Union Find"""
	def __init__(self, number_of_initial_sets):
		super(DisjoinSet, self).__init__()
		self.parent = range(number_of_initial_sets)
		self.elements_in_root = [1] * number_of_initial_sets
		self.sets_count = number_of_initial_sets


	def find_root(self, element):
		#print element, len(self.parent)
		if element == self.parent[element]:
			return element

		return self.find_root(self.parent[element])

	def join_sets(self, element_a, element_b):
		root_a, root_b = self.find_root(element_a), self.find_root(element_b)

		# belong to the same set
		if root_a == root_b:
			return False

		# element_b's root has more elements than element_a's root
		if self.elements_in_root[root_a] > self.elements_in_root[root_b]:
			element_a, element_b = element_b, element_a
			root_a, root_b = root_b, root_a

		self.elements_in_root[root_b] += self.elements_in_root[root_a]
		self.elements_in_root[root_a] = 0

		self.parent[root_a] = root_b
		self.sets_count -= 1

		return True

	def number_of_sets(self):
		return self.sets_count

N, M = map(int, raw_input().split())
disjoin_set = DisjoinSet(N)

distances = []

for _ in range(M):
	a, b, c = map(int, raw_input().split())
	distances.append([a-1, b-1, c])

distances.sort(key=lambda item: item[2])
distance_idx = 0

mst = []

while 1 != disjoin_set.number_of_sets():
	distance = distances[distance_idx]
	distance_idx += 1

	if disjoin_set.join_sets(distance[0], distance[1]):
		mst.append(distance)

#print mst
print sum([item[2] for item in mst])