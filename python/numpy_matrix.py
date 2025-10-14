#!/usr/bin/env python3
#Hacktoberfest2025
#Author: Golixco
import numpy as np

# simple arithmetic examples — Basic Python Program

# 1D array
a = np.array([1, 2, 3, 4, 5])
print("a =", a)

# 2D array (matrix)
b = np.array([[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]])
print("b:\n", b)

# element-wise arithmetic (1D)
print("a + 5 =", a + 5)                 # add scalar
print("a + [5,5,5,5,5] =", a + np.array([5,5,5,5,5]))  # add array
print("a - 1 =", a - 1)                 # subtract scalar
print("a * 2 =", a * 2)                 # multiply by scalar
print("a / 2 =", a / 2)                 # divide by scalar (float)
print("a ** 2 =", a ** 2)               # power
print("a % 2 =", a % 2)                 # modulo

# element-wise arithmetic (2D)
print("b * 2:\n", b * 2)                # element-wise multiply by scalar
print("b - 1:\n", b - 1)                # element-wise subtract

# matrix multiplication (dot product) — note: this is linear-algebraic multiplication
c = np.dot(b, b)
print("b dot b:\n", c)

# element-wise multiplication of matrices (different from dot)
print("b * b (element-wise):\n", b * b)

# small note: integer arrays give integer-ish results; convert if needed
b_float = b.astype(float)
print("b / 2 (float division):\n", b_float / 2.0)

# summary line (quick check)
print("Done — basic arithmetic ops shown.")
