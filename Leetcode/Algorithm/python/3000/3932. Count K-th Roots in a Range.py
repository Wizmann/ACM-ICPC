class Solution(object):
    def countKthRoots(self, l, r, k):
        if k == 1:
            return r - l + 1
        cur = int(pow(l, 1.0 / k)) - 1
        cur = 0
        cnt = 0
        while cur ** k <= r:
            if l <= cur ** k <= r:
                cnt += 1
            cur += 1
        return cnt
