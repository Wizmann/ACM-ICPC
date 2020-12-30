class Solution(object):
    def isRectangleOverlap(self, rec1, rec2):
        return not(
            max(rec2[0], rec2[2]) <= min(rec1[0], rec1[2])
            or
            min(rec2[0], rec2[2]) >= max(rec1[0], rec1[2])
            or
            max(rec2[1], rec2[3]) <= min(rec1[1], rec1[3])
            or
            min(rec2[1], rec2[3]) >= max(rec1[1], rec1[3])
        )
