from collections import defaultdict

N = 6666

class Solution(object):
    def triangleNumber(self, nums):
        prefix = [0 for i in xrange(N)]
        for num in nums:
            prefix[num] += 1
        for i in xrange(1, N):
            prefix[i] += prefix[i - 1]
            
        cnt = defaultdict(int)
        for num in nums:
            cnt[num] += 1
        
        ans = 0
        nums = sorted(set(filter(lambda x: x > 0, nums)))
        n = len(nums)
        for i in xrange(n):
            a = nums[i]
            if cnt[a] >= 2:
                ans += cnt[a] * (cnt[a] - 1) / 2 * (prefix[a * 2 - 1] - prefix[a])
            if cnt[a] >= 3:
                ans += cnt[a] * (cnt[a] - 1) * (cnt[a] - 2) / 6
            for j in xrange(i + 1, n):
                b = nums[j]
                s = a + b
                ans += (prefix[s - 1] - prefix[b]) * cnt[a] * cnt[b]
                if cnt[b] >= 2:
                    ans += cnt[a] * cnt[b] * (cnt[b] - 1) / 2
        return ans
