class Solution(object):
    def corpFlightBookings(self, bookings, n):
        pre = [0 for i in xrange(n + 2)]
        for (l, r, m) in bookings:
            pre[l] += m
            pre[r + 1] -= m
        res = []
        
        cur = 0
        for i in xrange(1, n + 1):
            cur += pre[i]
            res.append(cur)
        return res
