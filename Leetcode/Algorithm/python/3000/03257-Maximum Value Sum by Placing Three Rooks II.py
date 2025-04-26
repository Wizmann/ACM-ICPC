import heapq

INF = 10 ** 100

class Solution(object):
    def maximumValueSum(self, board):
        n = len(board)
        m = len(board[0])
        dp1 = [[] for i in xrange(n)]
        dp2 = [[] for i in xrange(n)]

        maxi = {}
        for i in xrange(n):
            for j in xrange(m):
                maxi[j] = max(board[i][j], maxi.get(j, -INF))
            dp1[i] = heapq.nlargest(3, map(lambda (k, v): (v, k), maxi.items()))
        
        maxi = {}
        for i in xrange(n - 1, -1, -1):
            for j in xrange(m):
                items[j] = max(board[i][j], maxi.get(j, -INF))
            dp2[i] = heapq.nlargest(3, map(lambda (k, v): (v, k), maxi.items()))
        
        res = -INF
        for i in xrange(1, n - 1):
            for j in xrange(m):
                for (v1, x1) in dp1[i - 1]:
                    for (v2, x2) in dp2[i + 1]:
                        if len(set([x1, x2, j])) != 3:
                            continue
                        res = max(res, v1 + v2 + board[i][j])
        return res
       

'''
^^^^^TEST^^^^
[[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]
---------------
4
$$$TEST$$$
'''
