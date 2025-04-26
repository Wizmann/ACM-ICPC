class Solution(object):
    def maxBottlesDrunk(self, numBottles, numExchange):
        tot = numBottles
        empty = numBottles
        while True:
            if empty >= numExchange:
                tot += 1
                empty -= numExchange
                empty += 1
                numExchange += 1
            else:
                break
        return tot
