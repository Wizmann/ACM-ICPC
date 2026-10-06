class Solution(object):
    def minimumOneBitOperations(self, n):
        if n <= 1:
            return n
        x = self.highestBit(n)
        res = 1 + self.solve(n ^ x, x / 2) + x - 1
        return res
    
    def solve(self, a, b):
        if self.highestBit(a) == b:
            return self.minimumOneBitOperations(a ^ b)
        return 1 + self.solve(a, b / 2) + b - 1
        
    def highestBit(self, n):
        for i in xrange(32, -1, -1):
            if n & (1 << i):
                return (1 << i)
        return 0

assert Solution().minimumOneBitOperations(12) == 8
assert Solution().minimumOneBitOperations(13) == 9
assert Solution().minimumOneBitOperations(4) == 7
assert Solution().minimumOneBitOperations(3) == 2
assert Solution().minimumOneBitOperations(0) == 0
