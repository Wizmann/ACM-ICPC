def solution(M, A):
    st = set()
    n = len(A)
    p, q = 0, 0
    res = 0
    while p < n and q < n:
        cur = A[q]
        if cur not in st:
            st.add(cur)
            q += 1
        else:
            res += q - p
            st.remove(A[p])
            p += 1
    if p < n:
        res += (1 + n - p) * (n - p) // 2
    return min(10 ** 9, res)
