class Solution(object):
    def largestSquareArea(self, bottomLeft, topRight):
        recs = zip(bottomLeft, topRight)
        maxi = 0
        n = len(recs)
        for i in xrange(n):
            for j in xrange(i + 1, n):
                rec1, rec2 = recs[i], recs[j]
                x1A, y1A = rec1[0]
                x1B, y1B = rec1[1]
                x2A, y2A = rec2[0]
                x2B, y2B = rec2[1]

                x1 = max(x1A, x2A)
                x2 = min(x1B, x2B)
                y1 = max(y1A, y2A)
                y2 = min(y1B, y2B)

                if x1 < x2 and y1 < y2:
                    # print rec1, rec2, min(x2 - x1, y2 - y1)
                    maxi = max(maxi, min(x2 - x1, y2 - y1))
        return maxi * maxi
