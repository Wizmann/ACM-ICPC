# https://leetcode.com/problems/angle-between-hands-of-a-clock/

class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        hour %= 12
        ah = 360. * (hour + 1.0 * minutes / 60) / 12.
        am = 1.0 * minutes / 60 * 360
        res = max(ah, am) - min(ah, am)
        print(ah, am, res)
        while res > 180:
            res = 360 - res          
        return res
