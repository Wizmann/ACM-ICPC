INF = 10 ** 10
BITS = 21

class Solution(object):
    def closestToTarget(self, arr, target):
        n = len(arr)
        
        bits = [ [0 for j in xrange(n)] for i in xrange(BITS) ]

        for i in xrange(BITS):
            mask = 1 << i
            pre = 0
            for j in xrange(n - 1, -1, -1):
                if arr[j] & mask:
                    pre += 1
                else:
                    pre = 0
                bits[i][j] = pre

        def calc(pos, m):
            res = 0
            for i in xrange(BITS):
                if bits[i][pos] >= m:
                    res |= 1 << i
            return res
        
        l, r = 0, 0
        cur = 0xffffffff
        res = INF
        while l < n and r < n:
            r = max(l, r)
            cur = calc(l, r - l + 1)
            res = min(res, abs(cur - target))
            while cur > target and r + 1 < n:
                r += 1
                cur = calc(l, r - l + 1)
                res = min(res, abs(cur - target))
            r = max(l, r - 1)
            l += 1
        return res

assert Solution().closestToTarget([5,89,79,44,45,79], 965) == 876
assert Solution().closestToTarget([1000000,1000000,1000000], 1) == 999999
assert Solution().closestToTarget([6, 5, 1], 1) == 0
assert Solution().closestToTarget([9,12,3,7,15], 5) == 2
assert Solution().closestToTarget([1,2,4,8,16], 0) == 0
