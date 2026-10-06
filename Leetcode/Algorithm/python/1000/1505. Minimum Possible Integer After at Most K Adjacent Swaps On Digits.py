from collections import defaultdict

class BinaryIndexedTree(object):
    def __init__(self, n):
        self.n = n + 1
        self.ns = [0 for i in xrange(n + 1)]

    def add(self, p, v):
        p += 1
        while p < self.n:
            self.ns[p] += v
            p += self.lowbit(p)

    def sum(self, a, b):
        return self.sum(b) - self.sum(a - 1)

    def sum(self, a):
        a += 1
        res = 0
        while a:
            res += self.ns[a]
            a -= self.lowbit(a)
        return res

    def lowbit(self, x):
        return x & -x

class Solution(object):
    def minInteger(self, num, k):
        num = map(int, num)
        d = defaultdict(list)

        for i, n in enumerate(num):
            d[n].append(i)

        n = len(num)
        ptr = 0
        res = ''
        t = BinaryIndexedTree(n)
        while ptr < n:
            # print k, ptr, num, res, t.ns
            if num[ptr] == -1:
                ptr += 1
                continue
            cur = num[ptr]
            for i in xrange(cur):
                if d[i]:
                    dis = d[i][0] - t.sum(d[i][0])
                    if dis <= k:
                        k -= dis
                        num[d[i][0]] = -1
                        t.add(d[i][0], 1)
                        d[i].pop(0)
                        res += str(i)
                        break
            else:
                assert d[num[ptr]][0] == ptr
                d[num[ptr]].pop(0)
                res += str(num[ptr])
                t.add(ptr, 1)
                ptr += 1
        # print res
        return res


assert Solution().minInteger("4321", 4) == "1342"
assert Solution().minInteger("100", 1) == "010"
assert Solution().minInteger("36789", 1000) == "36789"
assert Solution().minInteger("22", 22) == "22"
assert Solution().minInteger("294984148179", 11) == "124498948179"
assert Solution().minInteger("9438957234785635408", 23) == "0345989723478563548"

