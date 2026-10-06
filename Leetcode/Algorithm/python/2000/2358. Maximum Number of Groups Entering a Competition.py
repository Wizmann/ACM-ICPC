class Solution(object):
    def maximumGroups(self, grades):
        n = len(grades)
        rem = n
        cnt = 0
        for i in xrange(1, n + 1):
            rem -= i
            if rem < i + 1:
                rem = 0
            cnt += 1
            if rem == 0:
                break
        return cnt
