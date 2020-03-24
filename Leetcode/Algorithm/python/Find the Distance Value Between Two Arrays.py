class Solution(object):
    def findTheDistanceValue(self, arr1, arr2, d):
        arr1.sort()
        arr2.sort()
        
        p = 0
        q = 0
        res = 0
        for i, num in enumerate(arr1):
            while p < len(arr2) and num - arr2[p] > d:
                p += 1
            while q < len(arr2) and arr2[q] - num <= d:
                q += 1
            res += 0 if q - p else 1
        return res
