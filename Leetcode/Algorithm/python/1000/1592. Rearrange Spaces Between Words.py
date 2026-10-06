class Solution(object):
    def reorderSpaces(self, text):
        spaces = text.count(' ')
        words = text.split()
        if len(words) == 1:
            return words[0] + ' ' * spaces
        k = len(words) - 1
        return (' ' * (spaces / k)).join(words) \
               + ' ' * (spaces % k)
        
