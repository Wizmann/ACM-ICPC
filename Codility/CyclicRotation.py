def solution(A, K):
    if not A:
        return []
    n = len(A)
    K %= n
    K = n - K
    return A[K:] + A[:K]
