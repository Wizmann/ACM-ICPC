def C(a, b):
    c = 1
    for i in xrange(a):
        c *= b - i
        c /= i + 1
    return c

A = raw_input()
B = raw_input()

As = {}
Bs = {}
for c in ['+', '-', '?']:
    As[c] = A.count(c)

for c in ['+', '-', '?']:
    Bs[c] = B.count(c)

delta = max(As['+'] - Bs['+'], As['-'] - Bs['-'])

unr = Bs['?']

print '%.9f' % (1.0 * C(delta, unr) / (2 ** unr))
