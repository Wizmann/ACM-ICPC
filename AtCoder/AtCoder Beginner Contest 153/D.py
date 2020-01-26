d = {}
def solve(h):
    if h in d:
        return d[h]
    if h == 1:
        return 1
    else:
        res = solve(h / 2) * 2 + 1
        d[h] = res
        return res
 
assert solve(2) == 3
assert solve(4) == 7
assert solve(1000000000000) == 1099511627775
 
h = int(raw_input())
 
print solve(h)
