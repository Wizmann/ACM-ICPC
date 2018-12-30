def solve(s):
    n = len(s)
    ans = 0

    l = 1
    for i in xrange(1, n):
        if s[i] == s[i - 1]:
            l += 1
        else:
            break

    r = 1
    for i in xrange(n - 2, -1, -1):
        if s[i] == s[i + 1]:
            r += 1
        else:
            break

    if s[0] == s[-1]:
        ans = (l + 1) * (r + 1)
    else:
        ans = l + r + 1
    return ans % 998244353 

assert solve('abaa') == 6
assert solve('aacdeee') == 6
assert solve('ab') == 3


n = int(raw_input())
s = raw_input()
print solve(s)
