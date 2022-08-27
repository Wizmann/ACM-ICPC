class Solution(object):
    def countSpecialNumbers(self, n):
        ns = map(int, str(n))
        self.d = {}
        return self.dfs(ns, len(ns), 0, 0, False)
    
    def dfs(self, ns, n, cur, status, flag):
        if cur == n:
            return 1 if status else 0
        
        key = (cur, status)
        if flag and key in self.d:
            return self.d[key]
        
        res = 0
        for i in xrange(10):
            if status & (1 << i):
                continue
            if status == 0 and i == 0:
                nxt = status
            else:
                nxt = status | (1 << i)
            if not flag and ns[cur] < i:
                pass
            elif not flag and ns[cur] == i:
                res += self.dfs(ns, n, cur + 1, nxt, False)
            else:
                res += self.dfs(ns, n, cur + 1, nxt, True)
                
        if flag:
            self.d[key] = res
        return res
            

'''
^^^^TEST^^^^^
5
------
5
$$$TEST$$$$
^^^^TEST^^^^^
135
------
110
$$$TEST$$$$
^^^^TEST^^^^^
888
------
658
$$$TEST$$$$
^^^^TEST^^^^^
1581
------
1005
$$$TEST$$$$
^^^^TEST^^^^^
999
------
738
$$$TEST$$$$
^^^^TEST^^^^^
1000
------
738
$$$TEST$$$$
'''
