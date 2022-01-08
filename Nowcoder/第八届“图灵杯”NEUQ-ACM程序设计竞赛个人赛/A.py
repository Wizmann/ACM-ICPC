#coding=utf-8

N = 10

k = int(raw_input())

ops = []
cur = 0
for i in xrange(N):
    for j in xrange(1 << i):
        ops.append([1, i])

u = (2 ** N) / k
v = (2 ** N) % k
cakes = []
for i in xrange(k):
    cnt = u
    if v:
        cnt += 1
        v -= 1
    tot = 0
    op = [2, cnt]
    for j in xrange(cnt):
        op.append(N)
        tot += 1. / (2 ** N)
    ops.append(op)
    cakes.append(tot)

for cake in cakes:
    assert abs(1. / k - cake) <= (1.0 / (2 ** 10))
assert len(ops) <= 6000

print len(ops)
for op in ops:
    print ' '.join(map(str, op))

'''
^^^TEST^^^
2
-----
NULL
$$$TEST$$$
'''
