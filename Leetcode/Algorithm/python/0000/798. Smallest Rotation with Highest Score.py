class Solution(object):
    def bestRotation(self, A):
        n = len(A)
        res = [0 for i in xrange(n)]
        for i, num in enumerate(A):
            res[(i - num + 1 + n) % n] -= 1
            
        maxi = -10 ** 10
        ans = -1
        
        for i in xrange(n):
            if i - 1 >= 0:
                res[i] += res[i - 1] + 1
            if res[i] > maxi:
                maxi = res[i]
                ans = i
        return ans
