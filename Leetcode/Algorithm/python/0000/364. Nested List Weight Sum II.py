class Solution(object):
    def depthSumInverse(self, nestedList):
        self.max_depth = -1
        self.values = []
        
        self.dfs(nestedList, 0)
        res = 0
        for (value, depth) in self.values:
            # print value, self.max_depth - depth
            res += value * (self.max_depth - depth + 1)
        return res
        
    def dfs(self, nestedList, depth):
        self.max_depth = max(self.max_depth, depth)
        for item in nestedList:
            if item.isInteger():
                self.values.append((item.getInteger(), depth))
            else:
                self.dfs(item.getList(), depth + 1)
