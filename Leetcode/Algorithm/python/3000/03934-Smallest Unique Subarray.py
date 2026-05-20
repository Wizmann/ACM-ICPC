class Solution(object):
    def smallestUniqueSubarray(self, nums):
        n = len(nums)

        freq = [0] * 100001
        unique = 0
        distinct = 0
        for x in nums:
            if freq[x] == 0:
                distinct += 1
                unique += 1
            elif freq[x] == 1:
                unique -= 1
            freq[x] += 1

        if unique:
            return 1
        if distinct == 1:
            return n

        mod = 1000000007
        base = 911382323
        inv_base = pow(base, mod - 2, mod)

        power = [1] * (n + 1)
        inv_power = [1] * (n + 1)
        pre = [0] * (n + 1)

        for i, x in enumerate(nums):
            power[i + 1] = power[i] * base % mod
            inv_power[i + 1] = inv_power[i] * inv_base % mod
            pre[i + 1] = (pre[i] + x * power[i]) % mod

        def ok(length):
            pre_local = pre
            inv_local = inv_power
            mod_local = mod
            cnt = {}
            get = cnt.get
            unique = 0
            limit = n - length + 1

            for i in xrange(limit):
                h = (pre_local[i + length] - pre_local[i]) * inv_local[i] % mod_local
                c = get(h, 0)
                if c == 0:
                    cnt[h] = 1
                    unique += 1
                elif c == 1:
                    cnt[h] = 2
                    unique -= 1

            return unique > 0

        l, r = 1, n
        while l < r:
            mid = (l + r) >> 1
            if ok(mid):
                r = mid
            else:
                l = mid + 1
        return l


"""
^^^test^^^
[3,3,3]
---
3
$$$test$$$

^^^test^^^
[2,1,2,3,3]
---
1
$$$test$$$

^^^test^^^
[1,1,2,2,1]
---
2
$$$test$$$
"""
