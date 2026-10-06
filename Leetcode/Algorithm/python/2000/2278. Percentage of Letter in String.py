class Solution(object):
    def percentageLetter(self, s, letter):
        n = len(s)
        c = s.count(letter)
        
        return 100 * c / n
