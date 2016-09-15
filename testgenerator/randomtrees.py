from random import *;
#geneare random trees
alpha = 3  # affects the depth of the tree. Smaller value generates deeper trees.
N = 5;
print( [ (randint(max(0, i-alpha), i), i+1) for i in range(N-1) ] )
