def solve(n):
    try:
        idx = n.index('0')
        return n[:idx] + n[idx + 1:]
    except ValueError, e:
        return n[1:]

assert solve('101') == '11'
assert solve('11') == '1'
assert solve('10011') == '1011'

print solve(raw_input())
