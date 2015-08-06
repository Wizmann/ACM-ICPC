class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isAnagram(self, s, t):
        s, t = map(lambda x: ''.join(sorted(list(x))), [s, t])
        return s == t
