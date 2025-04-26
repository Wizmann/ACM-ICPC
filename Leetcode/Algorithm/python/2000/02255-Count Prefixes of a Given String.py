class Solution(object):
    def countPrefixes(self, words, s):
        cnt = 0
        for word in words:
            if s.startswith(word):
                cnt += 1
        return cnt
