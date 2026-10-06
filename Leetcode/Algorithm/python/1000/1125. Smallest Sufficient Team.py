INF = 0xFFFFFFFFFFFFFFFF

class Solution(object):
    def countb(self, u):
        res = 0
        while u:
            res += u & 1
            u >>= 1
        return res
    
    def smallestSufficientTeam(self, req_skills, people):
        """
        :type req_skills: List[str]
        :type people: List[List[str]]
        :rtype: List[int]
        """
        m = len(req_skills)
        d = dict(zip(req_skills, range(m)))
        
        n = len(people)
        dp = {}
   
        dp[0] = 0
        pre = set()
        for nr, p in enumerate(people):
            u = 0
            for skill in p:
                if skill not in d:
                    continue
                u |= 1 << d[skill]
            if u == 0 or u in pre:
                continue
            pre.add(u)
            for i in xrange(1 << m):
                if i not in dp:
                    continue
                if (i & u) == u:
                    continue
                j = i | u
                a = self.countb(dp[i] | (1 << nr))
                b = self.countb(INF if j not in dp else dp[j])
                if a < b:
                    dp[j] = dp[i] | (1 << nr)

        res = []
        for i in xrange(n):
            if dp[(1 << m) - 1] & (1 << i):
                res.append(i)
        return res
