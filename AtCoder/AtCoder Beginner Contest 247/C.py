def solve(n):
    if n == 0:
        return []
    nxt = solve(n - 1)
    return nxt + [n] + nxt

n = int(raw_input())
res = solve(n)
print ' '.join(map(str, res))

'''
^^^^TEST^^^
2
----
1 2 1
$$$TEST$$$

^^^^TEST^^^
4
----
1 2 1 3 1 2 1 4 1 2 1 3 1 2 1
$$$TEST$$$
'''
