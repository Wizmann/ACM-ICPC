INF = 10 ** 10

class Solution(object): 
    def mctFromLeafValues(self, arr):
        self.arr = arr
        self.d = {}
        n = len(arr)
        return self.solve(0, n) - sum(arr)
    
    def solve(self, l, r):
        assert l != r
        if r - l == 1:
            return self.arr[l]
        
        if r - l == 2:
            return self.arr[l] * self.arr[l + 1] + self.arr[l] + self.arr[l + 1]
        
        if (l, r) in self.d:
            return self.d[(l, r)]
        
        res = INF
        for i in xrange(l + 1, r):
            ll = self.arr[l: i]
            rr = self.arr[i: r]
            res = min(res, 
                    max(ll) * max(rr)
                    + self.solve(l, i)
                    + self.solve(i, r))
        self.d[(l, r)] = res
        return res
