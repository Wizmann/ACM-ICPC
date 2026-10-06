class Solution(object):
    def maximumBags(self, capacity, rocks, additionalRocks):
        n = len(capacity)
        extra = []
        for i in xrange(n):
            extra.append(capacity[i] - rocks[i])
        extra.sort()
        
        for i in xrange(n):
            added = min(extra[i], additionalRocks)
            extra[i] -= min(extra[i], added)
            additionalRocks -= added
        
        return len(filter(lambda x: not x, extra))
