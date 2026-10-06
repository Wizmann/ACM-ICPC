from collections import defaultdict
from copy import deepcopy

class Solution(object):
    def findProductsOfElements(self, queries):
        ans = []
        self.countd = {}
        for (a, b, mod) in queries:
            a += 1
            b += 1
            st = self.find_upper_bound(a)
            end = self.find_upper_bound(b)

            # print st, end

            if self.count(end) > b:
                d2 = self.count(end - 1)
            else:
                d2 = self.count(end)

            d1 = self.count(st - 1)

            # print d1, d2

            p1 = sum(d1.values()) + 1
            p2 = sum(d2.values())

            d2 = deepcopy(d2)

            # print d1, d2
            for key, value in d1.items():
                d2[key] -= value

            # print st, end

            # print p1, p2, a, b
            # print d2

            if p1 < a:
                cnt = 0
                for i in xrange(64):
                    if st & (1 << i):
                        cnt += 1
                        # print '>>', p1, cnt, a - 1, 1 << i
                        if p1 + cnt <= a:
                            d2[1 << i] -= 1
                        else:
                            break
            # print d2
            if p2 < b:
                cnt = 0
                for i in xrange(64):
                    if end & (1 << i):
                        cnt += 1
                        if p2 + cnt <= b:
                            d2[1 << i] += 1
                        else:
                            break
            
            # print d2
            res = 1
            for key, value in d2.items():
                res = res * pow(key, value, mod) % mod
            ans.append(res)
        return ans

    def find_upper_bound(self, num):
        l, r = 0, 10 ** 15
        while l <= r:
            m = (l + r) / 2
            cnt = sum(self.count(m).values())
            if cnt < num:
                l = m + 1
            else:
                r = m - 1
        return l

    def count(self, num):
        if num == 0:
            return defaultdict(int)

        if num in self.countd:
            return self.countd[num]

        res = defaultdict(int)

        tmp = num
        for i in xrange(0, 8):
            tmp |= tmp >> (2 ** i)

        tmp ^= (tmp >> 1)

        lowbits = num ^ tmp

        cnt1 = self.count(lowbits)
        cnt2 = self.count(tmp - 1)

        for key, value in cnt1.items():
            res[key] += value
        for key, value in cnt2.items():
            res[key] += value
        res[tmp] += lowbits + 1

        if len(self.countd) < 123456 or (num & (num >> 1)) == 0:
            self.countd[num] = res
        assert 0 not in res

        return res

# print Solution().count(1)
# print Solution().count(2)
# print Solution().count(3)
# print Solution().count(4)
# print Solution().count(5)
# print Solution().count(6)
# assert Solution().find_upper_bound(1) == 1
# assert Solution().find_upper_bound(2) == 2
# assert Solution().find_upper_bound(3) == 3
# assert Solution().find_upper_bound(4) == 3
# assert Solution().find_upper_bound(5) == 4

'''

^^^^^^TEST^^^^^
[[0,0,14]]
----------
[1]
$$$TEST$$$$

^^^^^^TEST^^^^^
[[8,16,10],[9,19,4],[7,8,15],[1,12,19],[19,20,17],[2,13,5],[11,12,1],[10,20,6],[3,10,11]]
----------
[8, 0, 8, 12, 15, 4, 0, 2, 6]
$$$TEST$$$$

^^^^^^TEST^^^^^
[[10,18,19]]
----------
[6]
$$$TEST$$$$

^^^^^^TEST^^^^^
[[2,17,14],[10,18,19]]
----------
[8, 6]
$$$TEST$$$$

^^^^^^TEST^^^^^
[[8,8,3]]
----------
[1]
$$$TEST$$$$

^^^^^^TEST^^^^^
[[3,3,5]]
----------
[2]
$$$TEST$$$$

^^^^^^TEST^^^^^
[[1,3,7]]
----------
[4]
$$$TEST$$$$

^^^^^^TEST^^^^^
[[2,5,3]]
----------
[2]
$$$TEST$$$$

^^^^^^TEST^^^^^
[[7,7,4]]
----------
[2]
$$$TEST$$$$

^^^^^^TEST^^^^^
[[2,5,3],[7,7,4]]
----------
[2, 2]
$$$TEST$$$$
'''
