from itertools import permutations


def all_pair_permutations(a, b):
    """
    N = len(a) = len(b)
    O(N!)
    """
    for x in permutations(b):
        yield zip(a, x)

#Usage
a = ['a', 'b', 'c']
b = range(1, 4)

for p in all_pair_permutations(a, b):
   print '|'.join([ '{}-{}'.format(map(str, x)[0], map(str, x)[1]) for x in p])
