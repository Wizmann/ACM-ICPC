MOD = 10 ** 9 + 7

def lowbit(x):
    return x & (-x)

class BinaryIndexedTree(object):
    def __init__(self, n):
        self.n = n + 1
        self.tree = [ 0 for i in xrange(n + 1) ]
        
    def add(self, pos, value):
        while pos < self.n:
            self.tree[pos] += value
            pos += lowbit(pos)
    
    def sum(self, pos):
        res = 0
        while pos > 0:
            res += self.tree[pos]
            pos -= lowbit(pos)
        return res
    
    def sum_interval(self, a, b):
        assert a <= b
        return self.sum(b) - self.sum(a - 1)
    

class Solution(object):
    def createSortedArray(self, instructions):
        n = len(instructions)
        m = max(instructions) + 1
        
        bit = BinaryIndexedTree(m)
        
        res = 0
        for i, num in enumerate(instructions):
            l = bit.sum_interval(0, num - 1)
            r = bit.sum_interval(num + 1, m)
            res = (res + min(l, r)) % MOD
            bit.add(num, 1)
        return res
