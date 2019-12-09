import sys
import itertools

N = 1000000

def factor_(x):
    res = 1
    for i in xrange(1, x + 1):
        res *= i
    return res
f = []

for i in xrange(10):
    f.append(factor_(i))

def factor(x):
    return f[x]

def numfactor(x):
    x = map(int, str(x))
    res = 0
    for num in x:
        res += factor(num)
    return res

def move(x, loop):
    if x in loop:
        return 0
    loop.add(x)
    nxt = numfactor(x)
    return 1 + move(nxt, loop)

assert move(169, set()) == 3
assert move(871, set()) == 2
assert move(69, set()) == 5
assert move(145, set()) == 1
assert move(540, set()) == 2
assert move(78, set()) == 4

cnt = 0
for i in xrange(1, N):
    if i % 1000 == 0:
        print ">>", i
    u = move(i, set())
    if u == 60:
        cnt += 1
print cnt
