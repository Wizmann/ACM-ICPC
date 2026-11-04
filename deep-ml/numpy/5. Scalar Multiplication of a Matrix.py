import numpy as np
def scalar_multiply(matrix: list[list[int|float]], scalar: int|float) -> list[list[int|float]]:
    array = np.asarray(matrix, dtype=float)
    return array * scalar
