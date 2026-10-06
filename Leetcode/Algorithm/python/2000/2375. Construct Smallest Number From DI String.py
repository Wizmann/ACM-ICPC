class Solution(object):
    def smallestNumber(self, pattern):
        return self.solve(pattern, 1)
    
    def solve(self, pattern, base):
        # print pattern, base
        n = len(pattern)
        if not pattern:
            return str(base)
        if set(pattern) == set(['D']):
            return ''.join(map(str, range(base + n, base - 1, -1)))
        elif set(pattern) == set(['I']):
            return ''.join(map(str, range(base, base + n + 1, 1)))
        
        for i in xrange(n - 1, -1, -1):
            if pattern[i] == 'I':
                mid = str(base + n)
                # print 'mid', mid
                left = self.solve(pattern[:i], base)
                right = self.solve(pattern[i + 1:], base + i + 1)[1:]
                # print pattern, base, left, mid, right
                return left + mid + right

