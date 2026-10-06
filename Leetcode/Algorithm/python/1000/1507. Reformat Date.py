months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]

class Solution(object):
    def reformatDate(self, date):
        d, m, y = date.split()
        dd = int(d[:-2])
        mm = months.index(m) + 1
        yy = int(y)
        return '%d-%02d-%02d' % (yy, mm, dd)
