from quick_sort import QuickSort
import heapq
import math
from threading import Thread
# you can import any package that you need here
# write your code here


class Solution:
    """
    @param n: the number of child threads you need to use
    @param nums: an array of numbers
    @return: return sorted nums
    """
    def quick_sort_in_threadings(self, t, nums):
        n = len(nums)
        ts = []
        qs = []
        for i in range(t):
            qs.append(QuickSort(nums[i * n // t: (i + 1) * n // t]))
            ts.append(Thread(target=lambda : qs[i].sort()))
            ts[i].start()
        for t in ts:
            t.join()
        return self.merge_n_sorted_arrays(list(map(lambda q: q.nums, qs)))

    # You can use this method to merge several ordered arrays
    def merge_n_sorted_arrays(self, arrays):
        result = []
        heap = []
        for index, array in enumerate(arrays):
            if len(array) == 0:
                continue
            heapq.heappush(heap, (array[0], index, 0))

        while len(heap):
            val, x, y = heap[0]
            heapq.heappop(heap)
            result.append(val)
            if y + 1 < len(arrays[x]):
                heapq.heappush(heap, (arrays[x][y + 1], x, y + 1))

        return result
