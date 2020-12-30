class Solution(object):
    def arrayRankTransform(self, arr):
        brr = sorted(set(arr))
        d = {}
        for i, num in enumerate(brr):
            d[num] = i + 1
        return map(lambda num: d[num], arr)
