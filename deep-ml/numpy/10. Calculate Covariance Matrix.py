import numpy as np
def calculate_covariance_matrix(vectors: list[list[float]]) -> list[list[float]]:
    return np.atleast_2d(np.cov(vectors, rowvar=True, ddof=1)).tolist()
