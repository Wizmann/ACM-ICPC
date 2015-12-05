class TreeNode(object):
    def __init__(self, value):
        self.value = value
        self.neighbors = []
        self.heights = []
    
    def add_neighbor(self, neighbor):
        self.neighbors.append(neighbor)

class Solution(object):
    def findMinHeightTrees(self, n, edges):
        if n <= 1:
            return [0]
        self.nodes = [TreeNode(i) for i in xrange(n)]
        for edge in edges:
            a, b = edge
            self.nodes[a].add_neighbor(b)
            self.nodes[b].add_neighbor(a)
        self.dfs1(0, -1)
        (a, b) = sorted(self.nodes[0].heights + [0], reverse=True)[:2]
        print a, b
        self.res = []
        self.dfs2(0, -1, a, b)
        return self.res
    
    def dfs1(self, cur, father):
        cur_node = self.nodes[cur]
        max_h = 0
        for neighbor in cur_node.neighbors:
            if neighbor == father:
                cur_node.heights.append(0)
                continue
            h = self.dfs1(neighbor, cur)
            cur_node.heights.append(h)
            max_h = max(max_h, h)
        return max_h + 1
        
    def dfs2(self, cur, father, a, b):
        print '>>', cur, a, b
        if len(self.nodes[cur].heights) >= 3:
            b = max(b, sorted(self.nodes[cur].heights, reverse=True)[1])
        print cur, a, b
        if abs(a - b) <= 1:
            self.res.append(cur)
        m = max(self.nodes[cur].heights)
        for i, neighbor in enumerate(self.nodes[cur].neighbors):
            if neighbor == father:
                continue
            if self.nodes[cur].heights[i] == m:
                self.dfs2(neighbor, cur, a - 1, b + 1)
        
            
