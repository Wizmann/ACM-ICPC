class Solution(object):
    def queensAttacktheKing(self, queens, king):
        my = [-1, 1, 0, 0, -1, 1, -1, 1]
        mx = [0, 0, -1, 1, -1, 1, 1, -1]
        res = []
        for i in xrange(8):
            dy, dx = my[i], mx[i]
            ny, nx = king
            while 0 <= ny < 8 and 0 <= nx < 8:
                if [ny, nx] in queens:
                    res.append([ny, nx])
                    break
                ny += dy
                nx += dx
        return res
