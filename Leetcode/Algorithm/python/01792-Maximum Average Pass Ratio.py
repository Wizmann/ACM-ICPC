import heapq

class Solution(object):
    def maxAverageRatio(self, classes, extraStudents):
        def score(a, b):
            return -1.0 * (b - a) / (b * b + b)
        pq = []
        for (a, b) in classes:
            heapq.heappush(pq, (score(a, b), a, b))
        
        for i in xrange(extraStudents):
            (_, a, b) = heapq.heappop(pq)
            a += 1
            b += 1
            heapq.heappush(pq, (score(a, b), a, b))
            
        
        tot = 0
        for (_, a, b) in pq:
            tot += 1.0 * a / b
            # print a, b
        tot /= len(classes)
        return tot
