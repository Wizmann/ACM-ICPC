class Solution(object):
    def getNoZeroIntegers(self, n):
        N = n
        num = list(map(int, str(n)))[::-1]
        n = len(num)
        
        g = 0
        a = []
        for i in xrange(n):
            cur = num[i] - g
            if cur >= 2:
                a.append('1')
                g = 0
            elif cur <= 1:
                if i < n - 1:
                    a.append('2')
                    g = 1
                
        a = int(''.join(a[::-1]))
        b = N - a
        return [a, b]
