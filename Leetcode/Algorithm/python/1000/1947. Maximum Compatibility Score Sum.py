INF = 10 ** 10

class Solution(object):
    def maxCompatibilitySum(self, students, mentors):
        n = len(students)
        assert len(students) == len(mentors)
        dp = [ [-INF for i in xrange(1 << n)] for j in xrange(2) ]
        dp[0][0] = 0
        
        p = 0
        for i in xrange(n):
            dp[p ^ 1] = [-INF for ii in xrange(1 << n)]
            for j in xrange(n):
                u = 0
                for (a, b) in zip(students[i], mentors[j]):
                    u += (1 if a == b else 0)
                for k in xrange(1 << n):
                    if k & (1 << j): 
                        continue
                    dp[p ^ 1][k | (1 << j)] = max(dp[p ^ 1][k | (1 << j)], dp[p][k] + u)
            p ^= 1
        return dp[p][(1 << n) - 1]
