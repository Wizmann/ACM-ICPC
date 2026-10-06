from heapq import *
from collections import deque

INF = 10 ** 10

class Solution(object):
    def assignTasks(self, servers, tasks):
        for i, weight in enumerate(servers):
            servers[i] = (weight, i)
        heapify(servers)
        
        events = []
        pending = deque()
        res = []
        i = 0
        while True:
            while events and events[0][0] == i:
                _, weight, serverId = heappop(events)
                heappush(servers, (weight, serverId))
            
            if i < len(tasks):
                pending.append(tasks[i])
                
            while servers and pending:
                task = pending.popleft()
                weight, serverId = heappop(servers)
                heappush(events, (i + task, weight, serverId))
                res.append(serverId)
            
            # print i, pending, servers, events
            if i > len(tasks) and not pending:
                break
            elif i > len(tasks) and events:
                i = events[0][0]
            else:
                i += 1

        return res
