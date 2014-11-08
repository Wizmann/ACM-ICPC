class Solution:
    def canCompleteCircuit(self, gas, cost):
        fail, tot, ptr = 0, 0, 0
        for i, v in enumerate(map(lambda (x, y): x - y, zip(gas, cost))):
            tot += v
            if tot < 0:
                fail += tot
                tot, ptr = 0, i + 1
        return -1 if tot + fail < 0 else ptr
        
