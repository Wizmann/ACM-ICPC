from collections import Counter

class Solution(object):
    def countPairs(self, deliciousness):
        c = Counter(deliciousness)
        res = 0
        for (key, value) in c.items():
            for i in xrange(32):
                target = 1 << i
                if target <= key:
                    continue
                rem = target - key
                if rem < key:
                    continue
                elif rem == key:
                    res += c[rem] * (c[rem] - 1) / 2
                else:
                    res += c[rem] * value
            res %= (10 ** 9) + 7
        return res
