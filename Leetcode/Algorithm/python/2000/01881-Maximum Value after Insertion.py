class Solution(object):
    def maxValue(self, num, x):
        n = len(num)
        num = list(num)
        if num[0] == '-':
            for i in xrange(1, n):
                if int(num[i]) > x:
                    num = num[:i] + [str(x)] + num[i:]
                    break
            else:
                num = num + [str(x)]
        else:
            for i in xrange(n):
                if int(num[i]) < x:
                    num = num[:i] + [str(x)] + num[i:]
                    break
            else:
                num = num + [str(x)]
        return ''.join(num)
