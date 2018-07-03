import heapq

INF = 10 ** 10

class Solution(object):
    def mincostToHireWorkers(self, quality, wage, K):
        n = len(quality)
        ns = []
        pq = []
        for i in xrange(n):
            q, w = quality[i], wage[i]
            ns.append((1.0 * w / q, q))
        ns.sort()
        res = INF
        for (p, q) in ns:
            heapq.heappush(pq, -q)
            if len(pq) > K:
                heapq.heappop(pq)
            if len(pq) == K:
                res = min(res, -p * sum(pq))    
        return res
            
        
            
        
