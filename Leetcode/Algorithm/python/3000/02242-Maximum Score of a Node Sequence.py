from collections import defaultdict

class Solution(object):
    def maximumScore(self, scores, edges):
        g = defaultdict(list)
        for (a, b) in edges:
            g[a].append((scores[b], b))
            g[b].append((scores[a], a))
        for key in g.keys():
            g[key].sort(reverse=True)
        
        ans = -1
        for (a, b) in edges:
            for (_, c) in g[a][:3]:
                for (_, d) in g[b][:3]:
                    # print a, b, c, d
                    if len(set([a, b, c, d])) == 4:
                        tot = sum(map(lambda x: scores[x], [a, b, c, d]))
                        ans = max(ans, tot)
        return ans
