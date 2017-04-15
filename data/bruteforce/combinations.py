from itertools import combinations

d = range(5)
for x in combinations(d, 3):
    print x

# Or home made
def find_combinations(data, size):
    """
    N = len(data)
    O(2^N)
    """
    for mask in range(1, 1 << len(data)):
        if bin(mask).count('1') == size:
            yield [x for i, x in enumerate(data) if mask & (1 << i) > 0]

for x in find_combinations(d, 3):
    print x
