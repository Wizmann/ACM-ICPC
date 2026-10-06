class Solution(object):
    def duplicateZeros(self, arr):
        z = arr.count(0)
        n = len(arr)
        
        p = n + z - 1
        for i in xrange(n - 1, -1, -1):
            if arr[i] == 0:
                if p < n:
                    arr[p] = 0
                p -= 1
                if p < n:
                    arr[p] = 0
                p -= 1
            else:
                if p < n:
                    arr[p] = arr[i]
                p -= 1
        return arr
        
        
