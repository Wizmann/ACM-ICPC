class BITree(object):
    def __init__(self, n):
        self.n = n + 1
        self.nums = [0 for i in xrange(self.n + 1)]
        
    def lowbit(self, x):
        return x & (-x)
    
    def add(self, pos, value):
        while pos < self.n:
            self.nums[pos] += value
            pos += self.lowbit(pos)
    
    def query(self, pos):
        res = 0
        while pos:
            res += self.nums[pos]
            pos -= self.lowbit(pos)
        return res
    
    def query_range(self, a, b):
        return self.query(b) - self.query(a - 1)
