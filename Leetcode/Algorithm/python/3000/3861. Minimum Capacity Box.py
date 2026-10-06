INF = 10 ** 10

class Solution(object):
    def minimumIndex(self, capacity, itemSize):
        """
        :type capacity: List[int]
        :type itemSize: int
        :rtype: int
        """
        mini = -1
        minc = INF
        for i, c in enumerate(capacity):
            if c >= itemSize and c < minc:
                mini = i
                minc = c
        return mini
                
