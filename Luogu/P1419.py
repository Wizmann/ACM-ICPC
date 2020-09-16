INF = 10 ** 10
eps = 1e-4

def check(ns, L, U, ave):
    st = []
    n = len(ns)

    psum = ns[:]
    for i in xrange(n):
        psum[i] -= ave
        if i - 1 >= 0:
            psum[i] += psum[i - 1]
    psum = [0] + psum
    # print psum

    for i in xrange(n + 1):
        while st and i - st[0] > U:
            st.pop(0)
        if st and i - st[0] >= L and psum[i] - psum[st[0]] >= 0:
            return True
        while st and i - L + 1 >= 0 and psum[i - L + 1] <= psum[st[-1]]:
            st.pop()
        if i - L + 1 >= 0:
            st.append(i - L + 1)
    return False

assert check([3, -10000, 2], 2, 3, -3333)
assert check([3, -1, 2], 2, 2, 0.000)
assert check([3, -1, 2], 2, 2, 1.000)
assert check([3, -1, 2], 2, 2, 0.500)
assert check([3, -1, 2], 2, 2, 0.600)

def solve(ns, L, U):
    l = -10000.
    r = 10000.
    while abs(l - r) > eps:
        m = (l + r) / 2.
        # print l, r, check(ns, L, U, m)
        if check(ns, L, U, m):
            l = m
        else:
            r = m
    return l


n = int(raw_input())
L, U = map(int, raw_input().split())

ns = []
for i in xrange(n):
    ns.append(int(raw_input()))

print '%.3f' % solve(ns, L, U)
