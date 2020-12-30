class Solution(object):
    def threeConsecutiveOdds(self, arr):
        n = len(arr)
        for i in xrange(n - 2):
            if arr[i] % 2 == 1 and \
               arr[i + 1] % 2 == 1 and \
               arr[i + 2] % 2 == 1:
                return True
        return False

assert Solution().threeConsecutiveOdds([1, 3, 5])
assert Solution().threeConsecutiveOdds([7, 3, 5])
assert Solution().threeConsecutiveOdds([7, 3, 5, 1])
assert Solution().threeConsecutiveOdds([7, 3, 6, 1]) == False
assert Solution().threeConsecutiveOdds([1, 2, 3]) == False
assert Solution().threeConsecutiveOdds([1, 1, 1])
