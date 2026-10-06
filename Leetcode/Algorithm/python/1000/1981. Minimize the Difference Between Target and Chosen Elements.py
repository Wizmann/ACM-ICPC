INF = 10 ** 10

class Solution(object):
    def minimizeTheDifference(self, mat, target):
        n = len(mat)
        m = len(mat[0])
        dp = [0]
        for i in xrange(n):
            mini = INF
            nxt = set()
            line = set(mat[i])
            for num1 in dp:
                for num2 in line:
                    if num1 + num2 >= target:
                        mini = min(mini, num1 + num2)
                    else:
                        nxt.add(num1 + num2)
            if mini <= INF:
                nxt.add(mini)
            dp = list(nxt)
        res = INF
        for num in dp:
            res = min(res, abs(num - target))
        return res
                
                
            
            
