from collections import defaultdict

class Solution(object):
    def bestTeamScore(self, scores, ages):
        N = max(ages) + 1
        d = defaultdict(list)
        ps = sorted(zip(scores, ages))
        dp = [0 for i in xrange(N)]
        n = len(scores)
        for (score, age) in ps:
            maxi = max(dp[:age + 1])
            dp[age] = max(dp[age], maxi + score)
        return max(dp)
