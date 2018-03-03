class Solution:
    """
    @param: : the number of "1"s on a given timetable
    @return: all possible time
    """

    def binaryTime(self, num):
        res = []
        for h in xrange(12):
            for m in xrange(60):
                b = '{:b}{:b}'.format(h, m)
                if b.count('1') == num:
                    res.append("%d:%02d" % (h, m))
        return res
