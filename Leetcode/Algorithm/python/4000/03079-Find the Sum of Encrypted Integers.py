class Solution(object):
    def sumOfEncryptedInt(self, nums):
        tot = 0
        for num in nums:
            maxi = max(map(int, str(num)))
            tot += maxi * int('1' * len(str(num)))
        return tot
