#coding=utf-8

PRIME = 19
MOD = 0xdeadbeefcafebabe
N = 512345

MUL = [1 for i in xrange(N)]

for i in xrange(1, N):
    MUL[i] = MUL[i - 1] * PRIME % MOD


def solve(n, s):
    rem = n
    st = []
    h1, h2 = 0, 0
    cur = 0
    step = 0
    for i in xrange(n):
        c = s[i]
        if c == '(':
            st.append(c)
            cur += 1
            h1 = (h1 * PRIME + 1) % MOD
            h2 = (h2 + MUL[cur - 1] * 1) % MOD
        elif c == ')':
            if st and st[-1] == '(':
                st.pop()
            else:
                st.append(c)
            cur += 1

            h1 = (h1 * PRIME + 2) % MOD
            h2 = (h2 + MUL[cur - 1] * 2) % MOD
        else:
            assert False

        if (h1 == h2 and cur > 1) or not st:
            rem -= cur
            cur = 0
            h1, h2 = 0, 0
            st = []
            step += 1

    return step, rem


T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    s = raw_input()

    c, r = solve(n, s)
    print c, r

'''
^^^^TEST^^^
5
2
()
3
())
4
((((
5
)((()
6
)((()(
-------
1 0
1 1
2 0
1 0
1 1
$$$TEST$$$
'''
