class Solution(object):
    def checkOnesSegment(self, s):
        return len(filter(lambda x: x, s.split("0"))) <= 1
