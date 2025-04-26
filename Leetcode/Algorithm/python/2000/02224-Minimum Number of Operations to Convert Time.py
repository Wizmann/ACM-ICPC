class Solution(object):
    def convertTime(self, current, correct):
        current = self.toMin(current)
        correct = self.toMin(correct)
        
        if current > correct:
            correct += 24 * 60
        
        cnt = 0
        for adjustment in [60, 15, 5, 1]:
            u = (correct - current) / adjustment
            cnt += u
            current += adjustment * u
        return cnt
    def toMin(self, s):
        hh, mm = map(int, s.split(":"))
        return hh * 60 + mm
