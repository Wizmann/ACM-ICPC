def solve(a, b, c):
    b -= 1
    c -= 2
    return min(a, b, c) * 3 + 3

assert solve(8, 13, 9) == 24
assert solve(13, 3, 6) == 9
assert solve(1, 2, 6) == 6

(a, b, c) = map(int, raw_input().split())
print solve(a, b, c)
