import numpy as np

def transform_matrix(
    A: list[list[int | float]],
    T: list[list[int | float]],
    S: list[list[int | float]],
) -> list[list[float]] | int:
    try:
        A = np.asarray(A, dtype=float)
        T = np.asarray(T, dtype=float)
        S = np.asarray(S, dtype=float)
        m, n = A.shape
        np.linalg.solve(S, np.eye(n))
        return np.linalg.solve(T, A @ S).tolist()

    except (ValueError, TypeError, OverflowError, np.linalg.LinAlgError):
        return -1
