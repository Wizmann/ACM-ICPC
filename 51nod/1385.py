def solve(s):
    l = len(s) - 1
    b = ((10 ** len(s)) - 1) / 9
    res = 0
    s = int(s)
    for i in xrange(1, 10):
        if s >= b * i:
            res += 1
    return res + l * 10

assert solve('10') == 10
assert solve('12') == 11
assert solve('2') == 2

s = raw_input()

print solve(s)

