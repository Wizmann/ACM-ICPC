class Solution(object):
    def reformat(self, s):
        a = filter(lambda c: c.isalpha(), s)
        n = filter(lambda c: c.isdigit(), s)
        
        res = ''
        if len(a) == len(n):
            for i in xrange(len(a)):
                res += a[i]
                res += n[i]
        elif abs(len(a) - len(n)) == 1:
            if len(a) < len(n):
                a, n = n, a
            res += a[-1]
            for i in xrange(len(n)):
                res += n[i]
                res += a[i]
        return res
