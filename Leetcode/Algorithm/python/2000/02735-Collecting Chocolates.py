class Solution(object):
    def minCost(self, nums, x):
        cur = sum(nums)
        n = len(nums)
        mini = cur
        ns = nums[:]
        for i in xrange(1, n):
            nxt = cur + x
            p, q = 0, i
            for j in xrange(n):
                if ns[p] > nums[q]:
                    nxt = nxt - ns[p] + nums[q]
                    ns[p] = nums[q]
                p = (p + 1) % n
                q = (q + 1) % n
            mini = min(nxt, mini)
            cur = nxt
        return mini
