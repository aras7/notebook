from math import factorial
from operator import mul


def permutations_with_repetitions(N, list_elements):
    return factorial(N) / reduce(mul, map(lambda x: factorial(int(x)), list_elements))