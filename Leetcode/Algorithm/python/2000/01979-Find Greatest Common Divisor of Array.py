def gcd(a, b):
    while a % b:
        a, b = b, a % b
    return b

class Solution(object):
    def findGCD(self, nums):
        maxi = max(nums)
        mini = min(nums)
        
        return gcd(maxi, mini)
