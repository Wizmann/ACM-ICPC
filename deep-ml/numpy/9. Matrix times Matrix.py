import numpy as np

def matrixmul(a:list[list[int|float]],
              b:list[list[int|float]])-> list[list[int|float]]:
    a = np.asarray(a, dtype=float)
    b = np.asarray(b, dtype=float)
    n1, m1 = a.shape
    n2, m2 = b.shape
    if m1 != n2:
        return -1
    return a @ b
