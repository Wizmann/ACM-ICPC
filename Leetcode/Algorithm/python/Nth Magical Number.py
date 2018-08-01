MOD = (10 ** 9) + 7

def gcd(a, b):
    while a % b != 0:
        a, b = b, a % b
    return b

def lcm(a, b):
    return a * b / gcd(a, b)

class Solution(object):
    def nthMagicalNumber(self, N, A, B):
        l, r = 1, 1 << 64
        C = lcm(A, B)
        while l <= r:
            m = (l + r) >> 1
            cnt = m / A + m / B - m / C
            if cnt >= N:
                r = m - 1
            else:
                l = m + 1
        return l % MOD
        
