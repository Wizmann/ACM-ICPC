INF = 10 ** 10

class Solution(object):
    def minMoves(self, nums, k):
        ones = []
        for i, num in enumerate(nums):
            if num == 1:
                ones.append(i)
            
        tot = 0
        ans = INF
        mid = k / 2
        m = len(ones)
        for i in xrange(0, k):
            diff = abs(i - k / 2)
            tot += abs(ones[k / 2] - ones[i]) - diff
        ans = min(ans, tot)
        
        for i in xrange(k, m):
            tot -= ones[mid] - ones[i - k] - k / 2
            diff = ones[mid + 1] - ones[mid] - 1
            tot += diff * (k / 2)
            tot -= diff * (k - k / 2 - 1)
            mid += 1
            tot += ones[i] - ones[mid] - (k - k / 2 - 1)
            ans = min(ans, tot)
        return ans

assert Solution().minMoves([1,0,0,1,0,1], 2) == 1
assert Solution().minMoves([1,0,0,1,0,1,1,1,0,1,1], 7) == 6
