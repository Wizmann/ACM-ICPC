MOD = (10 ** 9) + 7

class Solution(object):
    def numOfSubarrays(self, arr):
        even, odd = 0, 0
        tot = 0
        for num in arr:
            tot += num
            if tot % 2 == 0:
                even += 1
            else:
                odd += 1
        res = 0
        for num in arr:
            res += odd
            if num % 2 == 0:
                even -= 1
            else:
                odd -= 1
                even, odd = odd, even
            res %= MOD
        return res
