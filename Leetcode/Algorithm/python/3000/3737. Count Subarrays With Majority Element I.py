class Solution(object):
    def countMajoritySubarrays(self, nums, target):
        n = len(nums)
        for i in xrange(n):
            if nums[i] == target:
                nums[i] = 1
            else:
                nums[i] = 0
            if i - 1 >= 0:
                nums[i] += nums[i - 1]
        
        res = 0
        for i in xrange(n):
            for j in xrange(i + 1):
                m = i - j + 1
                cnt = nums[i] - (nums[j - 1] if j - 1 >= 0 else 0)
                if cnt * 2 > m:
                    res += 1
                    # print(cnt, m, j, i)
        return res
