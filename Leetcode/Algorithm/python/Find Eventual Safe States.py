from collections import defaultdict

class Solution(object):
    def eventualSafeNodes(self, graph):
        n = len(graph)
        rg = defaultdict(list)
        outd = [0 for i in xrange(n)]
        buckets = defaultdict(set)

        for i, siblings in enumerate(graph):
            for sibling in siblings:
                rg[sibling].append(i)
                outd[i] += 1

        for i, item in enumerate(outd):
            buckets[item].add(i)

        res = []
        while buckets.get(0, set()):
            item = buckets[0].pop()
            res.append(item)
            for neighbor in rg[item]:
                u = outd[neighbor]
                outd[neighbor] -= 1
                buckets[u].remove(neighbor)
                buckets[u - 1].add(neighbor)
        return sorted(res)
