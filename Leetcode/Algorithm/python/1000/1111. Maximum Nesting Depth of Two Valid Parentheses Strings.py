class Solution(object):
    def maxDepthAfterSplit(self, seq):
        depth = 0
        n = len(seq)
        ns = [0 for i in xrange(n)]
        
        for i, c in enumerate(seq):
            if c == '(':
                ns[i] = depth
                depth += 1
            else:
                depth -= 1
                ns[i] = depth
        m = max(ns)
        return map(lambda x: 1 if x > m / 2 else 0, ns)
