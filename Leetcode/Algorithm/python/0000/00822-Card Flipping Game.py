class Solution(object):
    def flipgame(self, fronts, backs):
        s = set()
        n = len(fronts)
        assert n == len(backs)
        
        for i in xrange(n):
            if fronts[i] == backs[i]:
                s.add(fronts[i])
        for num in sorted(set(fronts + backs)):
            if num not in s:
                return num
        return 0
