from collections import defaultdict

class Solution(object):
    def findSpecialInteger(self, arr):
        n = len(arr)
        d = defaultdict(int)
        for i in xrange(20):
            d[arr[i * n / 20]] += 1
        return sorted(d.items(), key=lambda (k, v): v)[-1][0]
            
