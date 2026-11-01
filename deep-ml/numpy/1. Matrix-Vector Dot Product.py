import numpy as np

def matrix_dot_vector(a: list[list[int|float]], b: list[int|float]) -> list[int|float]:
	# Return a list where each element is the dot product of a row of 'a' with 'b'.
	# If the number of columns in 'a' does not match the length of 'b', return -1.
	a = np.asarray(a)
	b = np.asarray(b)
	# print(list(a.shape), b.shape[::-1])
	if a.shape[-1] != b.shape[0]:
		return -1
	return a @ b
