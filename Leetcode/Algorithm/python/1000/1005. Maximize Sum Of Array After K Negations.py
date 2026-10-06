class Solution(object):
    def largestSumAfterKNegations(self, A, K):
        l = sorted(filter(lambda x: x < 0, A))
        for i in xrange(len(l)):
            if not K:
                break
            l[i] = -l[i]
            K -= 1
        K %= 2
        r = sorted(filter(lambda x: x >= 0, A) + l)
        if K:
            r[0] = -r[0]
        return sum(r)
