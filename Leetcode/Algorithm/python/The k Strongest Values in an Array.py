class Solution(object):
    def getStrongest(self, arr, k):
        n = len(arr)
        arr.sort()
        mid = arr[(n - 1) / 2]
        return sorted(arr, key=lambda x: (abs(x - mid), x), reverse=True)[:k]
        
        
