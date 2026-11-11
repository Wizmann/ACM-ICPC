import numpy as np
def solve_jacobi(A: np.ndarray, b: np.ndarray, n: int) -> list:
    A = np.asarray(A, dtype=float)
    b = np.asarray(b, dtype=float)

    diagonal = np.diag(A)
    remainder = A - np.diag(diagonal)

    x = np.zeros_like(b)

    for _ in range(n):
        x = (b - remainder @ x) / diagonal

    return np.round(x, 4)
