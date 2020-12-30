def lowbit(x):
    return x & (-x)

class Solution(object):
    def hasAlternatingBits(self, n):
        a = n ^ (n >> 1)
        b = a ^ (a >> 1)
        c = b - lowbit(b)
        return c == 0
