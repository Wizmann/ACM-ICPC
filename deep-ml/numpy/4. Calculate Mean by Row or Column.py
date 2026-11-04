import numpy as np

def calculate_matrix_mean(matrix: list[list[float]], mode: str) -> list[float]:
	array = np.asarray(matrix, dtype=float)
	axis = 1 if mode == "row" else 0
	return array.mean(axis=axis).tolist()
