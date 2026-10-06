class Solution(object):
    def checkRecord(self, s):
        return s.count('A') <= 1 and s.count('LLL') == 0
