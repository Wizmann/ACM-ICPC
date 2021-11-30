from collections import deque

class Solution(object):
    def timeRequiredToBuy(self, tickets, k):
        n = len(tickets)
        tickets = zip(tickets, range(n))
        tick = 0
        res = [-1 for i in xrange(n)]
        q = deque(tickets)
        while q:
            (u, cur) = q.popleft()
            if u == 1:
                res[cur] = tick
            else:
                q.append((u - 1, cur))
                
            tick += 1
            # print q
        # print res
        return res[k] + 1 
            
