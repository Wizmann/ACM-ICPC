# https://leetcode.com/problems/design-underground-system/

from collections import defaultdict

class UndergroundSystem:

    def __init__(self):
        self.cnt = defaultdict(int)
        self.tot = defaultdict(int)
        self.d = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.d[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        (s1, t1) = self.d[id]
        del self.d[id]
        (s2, t2) = stationName, t
        self.cnt[(s1, s2)] += 1
        self.tot[(s1, s2)] += t2 - t1

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        t = self.tot[(startStation, endStation)]
        c = self.cnt[(startStation, endStation)]
        return t / c


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
