class Solution(object):
    def countConsistentStrings(self, allowed, words):
        allowed = set(allowed)
        return len(filter(lambda word: set(word).issubset(allowed), words))
