mv = [(0, -1), (1, 0), (0, 1), (-1, 0)]

class Solution(object):
    def isRobotBounded(self, ins):
        d, dy, dx = 0, 0, 0
        for step in ins:
            if step == 'G':
                dy += mv[d][0]
                dx += mv[d][1]
            elif step == 'L':
                d = (d + 1) % 4
            elif step == 'R':
                d = (d + 3) % 4
            else:
                assert False
        print d, dy, dx
        return d != 0 or (dy == 0 and dx == 0)
