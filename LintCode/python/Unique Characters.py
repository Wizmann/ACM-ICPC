class Solution:
    # @param s: a string
    # @return: a boolean
    def isUnique(self, str):
        return len(set(str)) == len(str)
