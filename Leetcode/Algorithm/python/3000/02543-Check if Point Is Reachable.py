def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

class Solution(object):
    def isReachable(self, targetX, targetY):
        while targetX % 2 == 0:
            targetX /= 2
        while targetY % 2 == 0:
            targetY /= 2
        return gcd(targetX, targetY) == 1
