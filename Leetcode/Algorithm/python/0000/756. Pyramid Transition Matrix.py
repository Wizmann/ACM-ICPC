from collections import defaultdict

class Solution(object):
    def __init__(self):
        self.d = defaultdict(set)
        
    def pyramidTransition(self, bottom, allowed):
        for allow in allowed:
            self.d[allow[0] + allow[1]].add(allow[2])
        bottom = [set(c) for c in bottom]
        n = len(bottom)
        
        for i in xrange(n - 1):
            next = []
            for j in xrange(len(bottom) - 1):
                s = set()
                for a in bottom[j]:
                    for b in bottom[j + 1]:
                        s |= self.d[a + b]
                next.append(s)
            bottom = next
        return len(bottom[0]) != 0
