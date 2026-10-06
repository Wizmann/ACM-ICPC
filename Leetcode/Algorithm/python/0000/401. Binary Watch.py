def solve(count):
    ans = []
    for i in xrange(0, 12):
        for j in xrange(0, 60):
            c1 = '{:b}'.format(i).count('1')
            c2 = '{:b}'.format(j).count('1')
            if (c1 + c2 == count):
                ans.append("%d:%02d" % (i, j))
    return ans

class Solution(object):
    def readBinaryWatch(self, num):
        return solve(num)
