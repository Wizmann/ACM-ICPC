from collections import defaultdict

class Solution(object):
    def killProcess(self, pid, ppid, kill):
        d = defaultdict(list)
        n = len(pid)
        for i in xrange(n):
            p = pid[i]
            parent = ppid[i]
            
            d[parent].append(p)
            
        res = []
        self.dfs(d, kill, res)
        return res
        
    def dfs(self, d, kill, res):
        res.append(kill)
        for child in d[kill]:
            self.dfs(d, child, res)
