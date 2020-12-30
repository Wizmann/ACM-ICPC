INF = 10 ** 10

class Solution(object):
    def minHeightShelves(self, books, shelf_width):
        self.books = books
        self.n = len(self.books)
        self.m = shelf_width
        self.d = {}
        return self.dfs(0)
    
    def dfs(self, cur):
        if cur == self.n:
            return 0
        if cur in self.d:
            return self.d[cur]
        
        rem = self.m
        h = 0
        res = INF
        i = cur
        while i < self.n:
            (x, y) = self.books[i]
            if rem < x:
                break
            rem -= x
            h = max(h, y)
            res = min(res, h + self.dfs(i + 1))
            i += 1
        self.d[cur] = res
        return res
