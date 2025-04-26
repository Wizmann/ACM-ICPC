class Solution(object):
    def newInteger(self, n):
        u = 9 ** 10
        res = ''
        while u:
            res += str(n / u)
            n %= u
            u /= 9
        return int(res)
            
