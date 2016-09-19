def climb(n):
    res = []
    while n:
        res.append(n)
        n /= 2
    return res[::-1]
