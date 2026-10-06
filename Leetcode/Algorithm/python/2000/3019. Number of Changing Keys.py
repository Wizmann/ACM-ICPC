class Solution(object):
    def countKeyChanges(self, s):
        pre = None
        cnt = 0
        for c in s.lower():
            if c != pre:
                cnt += 1 if pre else 0
                pre = c
        return cnt
