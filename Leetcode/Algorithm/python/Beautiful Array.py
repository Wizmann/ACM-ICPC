class Solution(object):
    def beautifulArray(self, N):
        if N <= 2:
            return range(1, N + 1)
        a = map(lambda x: x * 2, self.beautifulArray(N / 2))
        b = map(lambda x: x * 2 - 1, self.beautifulArray((N + 1) / 2))
        return a + b
        
