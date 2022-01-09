import datetime

class Solution(object):
    def dayOfYear(self, date):
        y, m, d = map(int, date.split('-'))
        return (datetime.datetime(y, m, d) - datetime.datetime(y, 1, 1)).days + 1
