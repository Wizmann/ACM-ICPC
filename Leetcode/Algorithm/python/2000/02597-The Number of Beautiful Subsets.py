from collections import defaultdict

class Solution(object):
    def beautifulSubsets(self, nums, k):
        d = defaultdict(int)
        nums.sort()
        self.ans = 0
        self.dfs(0, nums, k, d)
        return self.ans - 1

    def dfs(self, cur, num, k, d):
        n = len(num)
        self.ans += 1
        if cur == n:
            # print d
            return
        for i in xrange(cur, n):
            nxt = num[i]
            if d[(nxt - k)] > 0:
                continue
            d[nxt] += 1
            self.dfs(i + 1, num, k, d)
            d[nxt] -= 1
        

