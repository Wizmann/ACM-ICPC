class Solution(object):
    def minTimeToType(self, word):
        cur = 0
        cnt = 0
        for c in word:
            c = ord(c) - ord('a')
            diff = min(abs(c - cur), abs(26 - abs(c - cur)))
            cnt += diff + 1
            cur = c
        return cnt
