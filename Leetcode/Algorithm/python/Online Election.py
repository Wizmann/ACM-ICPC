from collections import defaultdict

class TopVotedCandidate(object):

    def __init__(self, persons, times):
        self.n = len(persons)
        self.res = [(-1, -1, -1) for i in xrange(self.n)]
        assert len(persons) == len(times)
        
        d = defaultdict(list)
        for i, num in enumerate(persons):
            d[num].append(i)
        
        for num, l in d.items():
            for i, app in enumerate(l):
                self.res[app] = max(self.res[app], (i + 1, app, num))
                
        for i in xrange(1, self.n):
            self.res[i] = max(self.res[i], self.res[i - 1])
            
        self.times = times

    def q(self, t):
        l, r = 0, self.n - 1
        while l <= r:
            m = (l + r) / 2
            if self.times[m] > t:
                r = m - 1
            else:
                l = m + 1
        cnt, last, ans = self.res[r]
        return ans


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
