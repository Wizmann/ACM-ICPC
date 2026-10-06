from collections import Counter
class Solution(object):
    def firstUniqChar(self, s):
        cnt = Counter(s)
        for i, c in enumerate(s):
            if cnt[c] == 1:
                return i
        else:
            return -1
