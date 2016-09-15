from random import *
N = 15;
graph = ( [ (i,j) for i in range(N) for j in range(i) if randint(0,1) ] )
print graph
