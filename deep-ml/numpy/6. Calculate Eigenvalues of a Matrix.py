import numpy as np
def calculate_eigenvalues(matrix: list[list[float|int]]) -> list[float]:
	mat = np.asarray(matrix)
	eigenvalues = np.linalg.eigvals(mat)
	return np.real_if_close(eigenvalues).tolist()
