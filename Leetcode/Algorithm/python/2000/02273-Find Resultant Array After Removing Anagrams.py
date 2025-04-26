class Solution(object):
    def removeAnagrams(self, words):
        d = {}
        res = []
        for word in words:
            key1 = ''.join(sorted(word))
            key2 = '' if not res else ''.join(sorted(res[-1]))
            if key1 != key2:
                res.append(word)
        return res
