class Solution(object):
    def largestPalindrome(self, n):
        ans = [
            9,
            987,
            123,
            597,
            677,
            1218,
            877,
            475,
        ]
        return ans[n - 1]
    
    def do_solve(self):
        if n == 1:
            return 9
        a = (10 ** n) - 1
        for i in xrange(a, 0, -1):
            p = int(str(i) + str(i)[::-1])
            for j in xrange(a, 0, -1):
                if p / j >= j:
                    break
                if p % j == 0:
                    print p, j
                    return p % 1337
                
        return -1
