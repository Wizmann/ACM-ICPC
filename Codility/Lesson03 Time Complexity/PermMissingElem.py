def solution(A):
    n = len(A)
    return sum(range(1, n + 2)) - sum(A)
