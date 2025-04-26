class Solution(object):
    def findKthNumber(self, m, n, k):
        l, r = 1, m * n
        while l <= r:
            mid = (l + r) / 2
            cnt = 0
            for i in xrange(1, m + 1):
                cnt += min(n, mid / i)
            # print mid, cnt, l, r
            if cnt >= k:
                r = mid - 1
            else:
                l = mid + 1
        return l
