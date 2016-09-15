#generate random string of length N
from random import *
N = 23
print( ''.join( choice('ABCabc123') for i in range(N) ) )
