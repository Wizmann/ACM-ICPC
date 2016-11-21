def do_solve(a, b, c):
    u = max(b, c)
    if a in [u - 1, u, u + 1]:
        return u + u - b - c
    elif a > u + 1:
        u = a - 1
        return u + u - b - c
    else:
        return u * 3 - a - b - c - 1

def solve(a, b, c):
    return min(
        do_solve(a, b, c),
        do_solve(b, c, a),
        do_solve(c, a, b)
    )

def test():
    assert solve(3, 2, 1) == 1
    assert solve(1, 0, 0) == 0
    assert solve(100, 0, 100) == 99

test()

(a, b, c) = map(int, raw_input().split())
print solve(a, b, c)
