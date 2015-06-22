class Solution:
    # @param dictionary: a list of strings
    # @return: a list of strings
    def longestWords(self, dictionary):
        res = []
        max_len = 0
        
        for word in dictionary:
            if len(word) == max_len:
                res.append(word)
            elif len(word) > max_len:
                res = [word]
                max_len = len(word)
        return res
