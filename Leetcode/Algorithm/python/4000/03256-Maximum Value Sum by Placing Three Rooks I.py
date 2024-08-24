from copy import deepcopy

INF = 10 ** 100

class Solution(object):
    def maximumValueSum(self, board):
        dp = { 0: 0 }
        n = len(board)
        m = len(board[0])
        maxi = -INF
        for line in board:
            linemax = max(line)
            for key, value in dp.items():
                cnt = 0
                kk = key
                while kk:
                    kk -= (kk) & (-kk)
                    cnt += 1
                if cnt == 2 and value + linemax <= maxi:
                    continue
                for i in xrange(m):
                    if key & (1 << i):
                        continue
                    vv = value + line[i]
                    # print line, i, value
                    if cnt == 2:
                        maxi = max(maxi, vv)
                    else:
                        kk = key | (1 << i)
                        dp[kk] = max(vv, dp.get(kk, -INF))
        return maxi


'''
^^^^^TEST^^^^
[[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]
---------------
4
$$$TEST$$$
'''





