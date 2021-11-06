class Solution(object):
    def numOfStrings(self, patterns, word):
        return len(filter(lambda p: p in word, patterns))
