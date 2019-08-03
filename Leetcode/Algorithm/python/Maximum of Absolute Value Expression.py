'''
(+a1+a2+i) - (+b1+b2+j)
(+a1-a2+i) - (+b1-b2+j)
(-a1+a2+i) - (-b1+b2+j)
(-a1-a2+i) - (-b1-b2+j)
'''

INF = 10 ** 10

class Solution(object):
    def maxAbsValExpr(self, arr1, arr2):
        res = -INF
        n = len(arr1)

        s = sorted([arr1[i] + arr2[i] + i for i in xrange(n)], reverse=True)
        res = max(res, s[0] - s[-1])
        
        s = sorted([arr1[i] - arr2[i] + i for i in xrange(n)], reverse=True)
        res = max(res, s[0] - s[-1])
        
        s = sorted([-arr1[i] + arr2[i] + i for i in xrange(n)], reverse=True)
        res = max(res, s[0] - s[-1])
        
        s = sorted([-arr1[i] - arr2[i] + i for i in xrange(n)], reverse=True)
        res = max(res, s[0] - s[-1])
        
        return res
