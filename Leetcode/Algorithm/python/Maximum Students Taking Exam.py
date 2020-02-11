# https://leetcode.com/problems/maximum-students-taking-exam/

INF = 10 ** 10

from collections import defaultdict

class Solution:
    def maxStudents(self, seats):
        n = len(seats)
        m = len(seats[0])
        dp = [[-INF for i in range(1 << m)] for j in range(2)]

        bits = {}
        for i in range(1 << m):
            bits[i] = '{:b}'.format(i).count('1')

        lines = [0 for i in range(n)]
        for i in range(n):
            for j in range(m):
                if seats[i][j] == '#':
                    lines[i] |= 1 << j
        
        def match(s1, s2):
            return not ((s2 & (s2 << 1)) or \
                       (s2 & (s2 >> 1)) or \
                       (s1 & (s2 << 1)) or \
                       (s1 & (s2 >> 1)))
        
        nxt = defaultdict(list)
        for i in range(1 << m):
            for j in range(1 << m):
                if match(i, j):
                    nxt[i].append(j)
        
        dp[1][0] = 0
        p, q = 0, 0
        for i in range(n):
            q = p ^ 1
            dp[p] = [-INF for i in range(1 << m)]
            
            for j in range(1 << m):
                if dp[q][j] < 0:
                    continue
                for k in nxt[j]:
                    if lines[i] & k:
                        continue
                    dp[p][k] = max(dp[p][k], dp[q][j] + bits[k])
            #print(dp[p][:1<<m])
            p = q
        res = 0
        for i in range(1 << m):
            res = max(res, dp[p ^ 1][i])
        return res
                    
