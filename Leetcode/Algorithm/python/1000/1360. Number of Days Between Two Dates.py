# https://leetcode.com/problems/number-of-days-between-two-dates/

import datetime

class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        def to_datetime(date):
            yy, mm, dd = map(int, date.split('-'))
            return datetime.datetime(yy, mm, dd)

        d1 = to_datetime(date1)
        d2 = to_datetime(date2)

        return abs((d2 - d1).days)

S = Solution()
assert (S.daysBetweenDates("2019-06-29", "2019-06-29") == 0)
assert (S.daysBetweenDates("2019-06-29", "2019-06-30") == 1)
assert (S.daysBetweenDates("2020-01-15", "2019-12-31") == 15)
