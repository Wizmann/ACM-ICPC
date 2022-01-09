class Solution(object):
    def maximumUnits(self, boxTypes, truckSize):
        boxTypes.sort(key=lambda (num, size): size, reverse=True)
        # print boxTypes
        
        res = 0
        for (num, size) in boxTypes:
            c = min(num, truckSize)
            res += c * size
            truckSize -= c
        return res
