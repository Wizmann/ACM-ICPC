N = 55

class Solution(object):
    def getSubarrayBeauty(self, nums, k, x):
        n = len(nums)
        cnt = [0 for i in xrange(N)]
        for i in xrange(k - 1):
            if nums[i] < 0:
                cnt[-nums[i]] += 1
        res = []
        for i in xrange(k - 1, n):
            if nums[i] < 0:
                cnt[-nums[i]] += 1
            if i - k >= 0 and nums[i - k] < 0:
                cnt[-nums[i - k]] -= 1
            
            pre = 0
            for j in xrange(N - 1, -1, -1):
                pre += cnt[j]
                if pre >= x:
                    res.append(-j)
                    break
            else:
                res.append(0)
        return res
