def solve(a, b, c):
    if c - a - b <= 0:
        return False
    return (4 * a * b) < ((c - a - b) ** 2)

assert solve(2, 3, 9) == False
assert solve(2, 3, 10) == True
assert solve(1, 1, 2) == False
assert solve(1, 1, 4) == False
assert solve(1, 1, 5) == True
assert solve(10 ** 9, 10 ** 9, 10 ** 9) == False
assert solve(4, 5, 16) == False

(a, b, c) = map(int, raw_input().split())
print 'Yes' if solve(a, b, c) else 'No'
