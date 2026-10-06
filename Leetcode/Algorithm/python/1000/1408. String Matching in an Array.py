class Solution(object):
    def stringMatching(self, words):
        res = []
        for word in words:
            if any([word != other and word in other for other in words]):
                res.append(word)
        return res
