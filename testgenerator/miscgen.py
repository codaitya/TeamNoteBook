from random import *
N = 5
#N random numbers between ato b
a = 15
b = 27
print( [ randint(a, b) for i in range(N) ] )
#N real numbers between ato b
print( [ uniform(a, b) for i in range(N) ] )

#random permutation
seq = list(range(1, N+1))
shuffle(seq)
print(seq)
