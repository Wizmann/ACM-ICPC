class Solution(object):
    def getWordsInLongestSubsequence(self, n, words, groups):
        a, b = 0, 0
        stra, strb = [], []
        for word, group in zip(words, groups):
            if group == 0:
                if b + len(word) > a:
                    a = b + len(word)
                    stra = strb + [word]
            else:
                if a + len(word) > b:
                    b = a + len(word)
                    strb = stra + [word]
            # print stra, strb
        if a > b:
            return stra
        else:
            return strb
