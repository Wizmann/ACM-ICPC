def solve(a, b):
    if sum(a) > sum(b):
        a, b = b, a

    b = b[::-1]

    assert len(a) == len(b)
    n = len(a)

    p, q = 0, 0
    step = 0
    while sum(a) != sum(b):
        delta = sum(b) - sum(a)
        da = 9 - a[p] if p < n else 0
        db = b[q] if q < n else 0
        step += 1

        if da > db:
            d = min(da, delta)
            a[p] += d
            p += 1
        else:
            d = min(db, delta)
            b[q] -= d
            q += 1
    return step

assert solve([0, 0, 0], [0, 0, 0]) == 0
assert solve([1, 2, 3], [4, 5, 6]) == 2
assert solve([0, 0, 1], [1, 3, 6]) == 1
assert solve([1, 9, 9], [0, 8, 8]) == 1

s = raw_input()
n = len(s)
a = sorted(map(int, s[n / 2:]))
b = sorted(map(int, s[:n / 2]))

print solve(a, b)
