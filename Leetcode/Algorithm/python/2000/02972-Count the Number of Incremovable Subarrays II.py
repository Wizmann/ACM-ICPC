xrange = range

INF = 10 ** 100

class Solution(object):
    def incremovableSubarrayCount(self, nums):
        n = len(nums)
        pre = INF
        q = n - 1
        for i in xrange(n - 1, -1, -1):
            if nums[i] < pre:
                q = i
                pre = nums[i]
            else:
                break

        tot = 0
        pre = -INF
        for i in xrange(n):
            q = max(q, i + 1)
            tot += n + 1 - q
            # print i, q, tot
            if nums[i] > pre:
                pre = nums[i]
                while q < n and nums[i] >= nums[q]:
                    q += 1
            else:
                break
        return tot


assert Solution().incremovableSubarrayCount([1,2,3,4]) == 10
assert Solution().incremovableSubarrayCount([1,9,6,9]) == 7
assert Solution().incremovableSubarrayCount([6,5,7,8]) == 7
