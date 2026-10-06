from collections import Counter

PRIMES = set([2, 3, 5, 7, 11, 13, 17, 19, 23, 29,  
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71,  
        73, 79, 83, 89, 97])

class Solution(object):
    def checkPrimeFrequency(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        c = Counter(nums)
        for v in c.values():
            if v in PRIMES:
                return True
        return False
