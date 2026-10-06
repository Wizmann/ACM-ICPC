# https://leetcode.com/problems/time-needed-to-inform-all-employees/

from collections import defaultdict 

class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        self.g = defaultdict(list)
        for i, m in enumerate(manager):
            self.g[m].append(i)
        self.informTime = informTime
        return self.dfs(headID, informTime[headID])
    
    def dfs(self, cur, curTime):
        res = curTime
        for sub in self.g[cur]:
            res = max(res, self.dfs(sub, curTime + self.informTime[sub]))
        return res
        
