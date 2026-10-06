presum = [0]

for i in xrange(1, 123456):
    presum.append(presum[-1] + i)

def do_find(lst, value):
    l, r = 0, len(lst) - 1
    while l <= r:
        m = (l + r) / 2
        if lst[m] <= value:
            l = m + 1
        else:
            r = m - 1
    return r

class Solution(object):
    def maximumEvenSplit(self, finalSum):
        if finalSum % 2:
            return []
        u = finalSum
        u /= 2
        idx = do_find(presum, u)
        base = u - presum[idx]

        res = []
        for i in xrange(idx):
            res.append((i + 1) * 2)
        res[-1] += base * 2
        assert sum(res) == finalSum
        return res

'''
^^^TEST^^^
12
------
[2, 4, 6]
$$$TEST$$$

^^^TEST^^^
28
------
[2, 6, 8, 12]
$$$TEST$$$
'''
