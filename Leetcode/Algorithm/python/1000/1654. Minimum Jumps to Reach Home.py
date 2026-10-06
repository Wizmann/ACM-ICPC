from collections import deque

INF = 10 ** 10

class Solution(object):
    def minimumJumps(self, forbidden, a, b, x):
        limit = max(max(forbidden), x) + a + b
        dp = [ [INF for j in xrange(limit + 1)] for i in xrange(2) ]
        dp[0][0] = 0
        forbidden = set(forbidden)
        
        q = deque([(0, 0)])
        visited = set()
        while q:
            (cur, flag) = q.popleft()
            
            nxt1 = cur + a
            if nxt1 <= limit and (nxt1 not in forbidden) and dp[0][nxt1] > dp[flag][cur] + 1:
                dp[0][nxt1] = dp[flag][cur] + 1
                if (nxt1, 0) not in visited:
                    visited.add((nxt1, 0))
                    q.append((nxt1, 0))
                    
            if flag == 0:
                nxt2 = cur - b
                if nxt2 >= 0 and (nxt2 not in forbidden) and dp[1][nxt2] > dp[flag][cur] + 1:
                    dp[1][nxt2] = dp[flag][cur] + 1
                    if (nxt2, 1) not in visited:
                        visited.add((nxt2, 1))
                        q.append((nxt2, 1))
        res = min(dp[0][x], dp[1][x])
        if res >= INF:
            return -1
        return res
