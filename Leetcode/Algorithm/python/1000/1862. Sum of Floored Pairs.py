from collections import Counter

N = (10 ** 5) + 1234
MOD = 10 ** 9 + 7

class Solution(object):
    def sumOfFlooredPairs(self, nums):
        pre = [0 for i in xrange(N)]
        for num in nums:
            pre[num] += 1
        for i in xrange(1, N):
            pre[i] += pre[i - 1]
        c = Counter(nums)

        res = 0
        for num in sorted(c.keys()):
            count = c[num]
            tot = 0
            for i in xrange(1, N / num + 1):
                l = num * i
                r = min(N - 1, num * (i + 1) - 1)
                u = pre[r] - pre[l - 1]
                # print num, l, r, i * u
                tot += i * u
            res = (res + tot * count % MOD) % MOD
        return res
        
'''
^^^TEST^^^
[2,5,9]
-------
10
$$$TEST$$$


^^^TEST^^^
[7,7,7,7,7,7,7]
-------
49
$$$TEST$$$

'''
