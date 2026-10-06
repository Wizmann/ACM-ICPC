class Solution(object):
    def countHillValley(self, nums):
        ns = []
        for num in nums:
            if not ns or ns[-1] != num:
                ns.append(num)
        n = len(ns)
        cnt = 0
        for i in xrange(1, n - 1):
            l = ns[i - 1]
            r = ns[i + 1]
            cur = ns[i]
            if l < cur > r or l > cur < r:
                cnt += 1
        return cnt
