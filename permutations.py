def find_combinations(data, size, prefix=[], used=0):
   if len(prefix) == size:
      yield prefix
   else:
      for idx, i in enumerate(range(len(data))):
         if ((1 << idx) & used) == 0:
             for perms in find_combinations(data, size, prefix + [data[i]], used | (1 << idx)):
                 yield perms

"""
si es permutacion, solo hay que borrar el size. me dio flojera hacerlo
"""
