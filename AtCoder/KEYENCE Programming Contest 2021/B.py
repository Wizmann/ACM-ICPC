#!/usr/bin/pypy

N = 1 << 19
LOGN = 19
INF = 10 ** 10

class RMQ(object):
    def __init__(self, logn):
        self.n = 1 << logn
        self.logn = logn
        self.rmq = [[0 for i in xrange(self.n)] for j in xrange(self.logn + 1)]

    def init(self, ns):
        assert len(ns) == self.n
        for i in xrange(self.n):
            self.rmq[0][i] = ns[i]

        for i in xrange(1, self.logn + 1):
            for j in xrange(N):
                cur = j
                nxt = min(self.n - 1, j + (1 << (i - 1)))
                self.rmq[i][cur] = min(self.rmq[i - 1][cur], self.rmq[i - 1][nxt])

    def query(self, a, b):
        res = INF
        for i in xrange(self.logn, -1, -1):
            if a + (1 << i) <= b:
                res = min(res, self.rmq[i][a])
                a += (1 << i)
        return res


(n, k) = map(int, raw_input().split())
ns = map(int, raw_input().split())

cs = [0 for i in xrange(N)]
for num in ns:
    cs[num] += 1

rmq = RMQ(LOGN)
rmq.init(cs)

cnt = 0
res = []
for i in xrange(N - 1, -1, -1):
    if cs[i] > cnt:
        mini = rmq.query(0, i)
        # print i, mini, cnt, cs[i]
        if mini > cnt:
            cur = min(mini - cnt, cs[i] - cnt)
            res += [i + 1] * cur
            cnt += cur

# print res

print sum(res[:k])




'''
^^^TEST^^^
4 2
0 1 0 2
----
4
$$$TEST$$$

^^^TEST^^^
5 2
0 1 1 2 3
----
4
$$$TEST$$$

^^^TEST^^^
20 4
6 2 6 8 4 5 5 8 4 1 7 8 0 3 6 1 1 8 3 0
----
11
$$$TEST$$$

'''


