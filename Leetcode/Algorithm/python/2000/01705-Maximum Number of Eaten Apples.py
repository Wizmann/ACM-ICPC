#coding=utf-8

import heapq

class Solution(object):
    def eatenApples(self, apples, days):
        n = len(days)
        assert n == len(apples)
        
        pq = []
        res = 0
 
        i = 0
        while pq or i < n:
            if i < n:
                item = [i + days[i], apples[i]]
                heapq.heappush(pq, item)
            while pq:
                if pq[0][0] <= i or pq[0][1] == 0:
                    heapq.heappop(pq)
                else:
                    # print pq[0]
                    pq[0][1] -= 1
                    res += 1
                    if not pq[0][1]:
                        heapq.heappop(pq)
                    break
            i += 1
        return res


