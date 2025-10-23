from itertools import chain
import time
import numpy as np

def transpose2(M):
    M = M.tolist() 
    n = len(M[0])
    L = list(chain(*M))
    return [L[i::n] for i in range(n)]

m = np.array([[1, 2, 3], [4, 5, 6]])

start = time.time_ns()
res = transpose2(m)
end = time.time_ns()

print(res)
print("Time taken", end - start, "ns")
