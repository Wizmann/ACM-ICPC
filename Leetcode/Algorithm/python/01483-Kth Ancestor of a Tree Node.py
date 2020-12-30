from collections import defaultdict

class TreeAncestor(object):
    def __init__(self, n, parent):
        self.anc = [ [-1 for i in xrange(32)] for i in xrange(n) ]
        self.d = defaultdict(list)        
        for i, p in enumerate(parent):
            if i == 0:
                continue
            self.d[p].append(i)
        self.dfs(0, -1)
        
    def dfs(self, cur, pre):
        self.anc[cur][0] = pre
        for i in xrange(1, 32):
            if self.anc[cur][i - 1] == -1:
                continue
            self.anc[cur][i] = self.anc[self.anc[cur][i - 1]][i - 1]
        for nxt in self.d[cur]:
            self.dfs(nxt, cur)
    
    def getKthAncestor(self, node, k):
        if k == 0:
            return node
        if node == -1:
            return node
        
        for i in xrange(31, -1, -1):
            if k & (1 << i):
                return self.getKthAncestor(self.anc[node][i], k - (1 << i))
        return -1      
        
        
# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)
