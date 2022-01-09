def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

class Solution(object):
    def isGoodArray(self, nums):
        return reduce(lambda x, y: gcd(x, y), nums) == 1
        
