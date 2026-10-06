def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

class Solution(object):
    def gcdSum(self, nums):
        maxi = 0
        n = len(nums)
        nums2 = []
        for num in nums:
            maxi = max(maxi, num)
            g = gcd(maxi, num)
            nums2.append(g)
        l, r = 0, n - 1
        tot = 0
        nums2.sort()
        #print nums2
        while l < r:
            tot += gcd(nums2[l], nums2[r])
            l += 1
            r -= 1
        return tot
