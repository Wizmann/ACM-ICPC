class Solution:
     # @param nums: a list of integers
     # @return: the maximum difference
    def maximumGap(self, nums):
        n = len(nums)
        if n == 0:
            return 0
            
        mini = min(nums)
        maxi = max(nums)
        if maxi == mini:
            return 0
        
        dis = (maxi - mini + n - 1) / n
        
        if dis == 0:
            return 0
        
        bucket = [None for i in xrange((maxi - mini) / dis + 1)]
        
        for i in nums:
            b = (i - mini) / dis
            if bucket[b] is None:
                bucket[b] = (i, i)
            else:
                bucket[b] = (
                    min(bucket[b][0], i),
                    max(bucket[b][1], i)
                )
        
        bucket = filter(lambda x: x, bucket)
        ans = 0
        for i, item in enumerate(bucket):
            ans = max(ans, abs(item[1] - item[0]))
            if i > 0:
                ans = max(ans, abs(bucket[i - 1][1] - bucket[i][0]))
        return ans
