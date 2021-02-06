class Solution(object):
    def trimMean(self, arr):
        arr.sort()
        n = len(arr)
        m = int(n * 0.05)
        arr = arr[m:-m]
        return 1.0 * sum(arr) / len(arr)
