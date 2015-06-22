class Solution:
    # @param {string} s A string
    # @return {int} the length of last word
    def lengthOfLastWord(self, s):
        try:
            return len(s.split()[-1])
        except:
            return 0
