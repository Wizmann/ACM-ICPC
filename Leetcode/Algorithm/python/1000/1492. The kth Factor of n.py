class Solution(object):
    def kthFactor(self, n, k):
        cnt = 0
        for i in xrange(1, n + 1):
            if n % i == 0:
                cnt += 1
                if cnt == k:
                    return i
        return -1
