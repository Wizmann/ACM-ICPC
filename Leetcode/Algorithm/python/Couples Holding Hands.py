class Solution(object):
    def minSwapsCouples(self, row):
        n = len(row)
        d = {}
        for i, item in enumerate(row):
            d[item] = i
            
        ans = 0
        for i in xrange(0, n, 2):
            a = row[i]
            b = row[i] + 1 if a % 2 == 0 else row[i] - 1
            if row[i + 1] != b:
                ans += 1
                c = d[b]
                d[row[i + 1]], d[b] = c, d[row[i + 1]]
                row[i + 1], row[c] = row[c], row[i + 1]
        return ans
