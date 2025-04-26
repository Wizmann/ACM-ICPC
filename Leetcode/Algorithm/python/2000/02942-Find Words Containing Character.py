class Solution(object):
    def findWordsContaining(self, words, x):
        res = []
        for i, word in enumerate(words):
            if x in word:
                res.append(i)
        return res
