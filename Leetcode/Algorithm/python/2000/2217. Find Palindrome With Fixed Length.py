class Solution(object):
    def kthPalindrome(self, queries, intLength):
        n = (intLength - 1) / 2
        base = 10 ** n
        
        res = []
        for q in queries:
            v = base + q - 1
            if v >= base * 10:
                res.append(-1)
                continue
            s = str(v)
            if intLength % 2 == 0:
                res.append(int(s + s[::-1]))
            else:
                res.append(int(s[:-1] + s[::-1]))
        return res
