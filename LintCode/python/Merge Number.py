import heapq

class Solution:
    """
    @param numbers: the numbers
    @return: the minimum cost
    """
    def mergeNumber(self, numbers):
        heapq.heapify(numbers)
        
        res = 0
        while len(numbers) >= 2:
            a = heapq.heappop(numbers)
            b = heapq.heappop(numbers)
            res += a + b
            heapq.heappush(numbers, a + b)
        return res
