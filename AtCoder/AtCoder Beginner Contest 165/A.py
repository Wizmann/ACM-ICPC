def solve(a, b, k):
    if a % k == 0:
        return a % k == 0
    return a / k < b / k

assert solve(12, 14, 4)
assert solve(11, 11, 1)
assert solve(11, 12, 1)
assert solve(11, 12, 3)
assert solve(11, 12, 5) == False
assert solve(3, 3, 3)
assert solve(1, 2, 3) == False
assert solve(5, 7, 4) == False
assert solve(7, 7, 7)
assert solve(3, 7, 4)
assert solve(5, 8, 4)
assert solve(5, 9, 4)
assert solve(500, 600, 7)

k = int(raw_input())
a, b = map(int, raw_input().split())

print 'OK' if solve(a, b, k) else 'NG'

