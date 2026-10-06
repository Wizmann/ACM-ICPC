class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        while tx > sx and ty > sy:
            ty, tx = ty % tx, tx % ty
        if sx == tx and (sy - ty) % tx == 0:
            return True
        if sy == ty and (sx - tx) % ty == 0:
            return True
        return False
