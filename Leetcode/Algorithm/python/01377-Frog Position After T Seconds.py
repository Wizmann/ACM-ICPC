# https://leetcode.com/problems/frog-position-after-t-seconds/

from collections import defaultdict

class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        self.res = 0
        self.g = defaultdict(list)
        for (a, b) in edges:
            self.g[a].append(b)
            self.g[b].append(a)
        self.dfs(-1, 1, 0, target, t, 1.0)
        return self.res
        
    def dfs(self, pre, cur, cur_t, target, target_t, p):
        cnt = len(list(filter(lambda x: x != pre, self.g[cur])))
        if cur == target:
            if cur_t == target_t:
                self.res = p
            elif cur_t < target_t and cnt == 0:
                self.res = p
            return
        if cur_t > target_t:
            return
        
        for nxt in self.g[cur]:
            if nxt == pre:
                continue
            self.dfs(cur, nxt, cur_t + 1, target, target_t, p / cnt)
        
