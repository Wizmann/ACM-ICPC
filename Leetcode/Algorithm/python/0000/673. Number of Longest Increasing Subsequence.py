class Node(object):
    def __init__(self, length, cnt):
        self.length = length
        self.cnt = cnt
        
    def __str__(self):
        return '(%d, %d)' % (self.length, self.cnt)

class Solution(object):
    def findNumberOfLIS(self, nums):
        n = len(nums)
        dp = [Node(1, 1) for i in xrange(n)]
        
        for i in xrange(1, n):
            maxi, cnt = 1, 1
            for j in xrange(i):
                if nums[i] > nums[j]:
                    if maxi < dp[j].length + 1:
                        maxi = dp[j].length + 1
                        cnt = dp[j].cnt
                    elif maxi == dp[j].length + 1:
                        cnt += dp[j].cnt
            dp[i] = Node(maxi, cnt) 
        maxi, cnt = 0, 0
        for i in xrange(n):
            #print dp[i]
            if dp[i].length > maxi:
                maxi = dp[i].length
                cnt = dp[i].cnt
            elif dp[i].length == maxi:
                cnt += dp[i].cnt
        return cnt
