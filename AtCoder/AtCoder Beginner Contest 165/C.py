def solve(a, b, n):
    return a * min(b - 1, n) / b

assert solve(5, 7, 4) == 2
assert solve(1, 1, 1) == 0
assert solve(11, 10, 9) == 9

(a, b, n) = map(int, raw_input().split())

print solve(a, b, n)

