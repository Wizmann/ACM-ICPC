class Solution(object):
    def validDigit(self, n, x):
        n = str(n)
        x = str(x)
        return (x in n) and (not n.startswith(x))
