def solve(x):
    x -= 400
    return 8 - x / 200

assert solve(400) == 8
assert solve(401) == 8
assert solve(599) == 8
assert solve(1599) == 3
assert solve(1800) == 1
assert solve(1999) == 1

x = int(raw_input())
print solve(x)
