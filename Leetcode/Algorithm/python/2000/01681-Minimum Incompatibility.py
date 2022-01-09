INF = 10 ** 10

class Solution(object):
    def minimumIncompatibility(self, nums, k):
        n = len(nums)
        k = n / k
        nums.sort()
        self.ans = INF
        self.dfs(nums, 0, [], k, 0, -1)
        if self.ans == INF:
            return -1
        return self.ans
    
    def dfs(self, nums, status, group, k, total, pre):
        if total >= self.ans:
            return
        if len(group) == k:
            diff = max(group) - min(group)
            total += diff
            group = []
            pre = -1
        n = len(nums)
        if status == (1 << n) - 1:
            self.ans = min(self.ans, total)
            return
        for i in xrange(pre + 1, n):
            if status & (1 << i):
                continue
            if nums[i] in group:
                continue
            group.append(nums[i])
            status |= 1 << i
            self.dfs(nums, status, group, k, total, i)
            status ^= 1 << i
            group.pop()
            if pre == -1:
                break
