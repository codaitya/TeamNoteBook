#Random graph of n vertices
N = 5
print(set((randint(0, i), i+1) for i in range(N-1)) | set((i,j) for i in range(N) for j in range(i) if randint(0,1))
