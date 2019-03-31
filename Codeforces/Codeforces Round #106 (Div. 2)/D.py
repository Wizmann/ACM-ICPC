MOD = 1000000000 + 7

s = raw_input()
n = len(s)
dp = {}

mt = [-1 for i in xrange(n)]

st = []
for i, c in enumerate(s):
    if c == '(':
        st.append(i)
    else:
        m = st.pop()
        mt[m] = i


def do_solve(before, l, r, after):
    if l == r + 1:
        return 1
    assert l <= r
    key = (before, l, r, after)
    if key in dp:
        return dp[key]

    if l == r:
        return 1

    m = mt[l]

    res = 0
    for i in [1, 2]:
        if m != r:
            res += do_solve(0, l + 1, m - 1, i) * do_solve(i, m + 1, r, after)
        elif m == r and i != after:
            res += do_solve(0, l + 1, m - 1, i)

    for i in [1, 2]:
        if i == before:
            continue

        if m != r:
            res += do_solve(i, l + 1, m - 1, 0) * do_solve(0, m + 1, r, after)
        else:
            res += do_solve(i, l + 1, m - 1, 0)
    res %= MOD
    dp[key] = res
    return res


print do_solve(-1, 0, n - 1, -1)

