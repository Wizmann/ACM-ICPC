def zeros(n):
    u = 0
    v = 5
    while n / v:
        u += n / v
        v *= 5
    return u
