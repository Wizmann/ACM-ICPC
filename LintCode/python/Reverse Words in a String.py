class Solution:
    # @param s : A string
    # @return : A string
    def reverseWords(self, s):
        return ' '.join(s.split()[::-1])
