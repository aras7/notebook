def all_rotate(word):
   size = len(word)
   for i in range(size):
      yield word[i:] + word[:i]


# Usage
for x in all_rotate('word'):
  print x
