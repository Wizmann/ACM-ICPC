class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        return len(s.split()[-1]) if s.strip() else 0
