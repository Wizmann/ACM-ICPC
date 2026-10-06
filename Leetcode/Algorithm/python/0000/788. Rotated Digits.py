class Solution(object):
    def rotatedDigits(self, N):
        ans = 0
        for i in xrange(1, N + 1):
            s = str(i)
            r = self.rotate(s)
            if 'x' not in r and s != r:
                ans += 1
        return ans
        
    def rotate(self, s):
        return ''.join(map(lambda c: {
            '0': '0',
            '1': '1',
            '8': '8',
            '2': '5',
            '5': '2',
            '6': '9',
            '9': '6'
        }.get(c, 'x'), s))
        
