from collections import defaultdict

class Solution(object):
    def canArrange(self, arr, k):
        n = len(arr)
        assert n % 2 == 0
        d = defaultdict(list)
        for num in arr:
            d[num % k].append(num)
        if len(d[0]) % 2:
            return False
        if k % 2 == 0 and len(d[k / 2]) % 2:
            return False
        for i in xrange(1, (k + 1) / 2):
            if len(d[i]) != len(d[k - i]):
                return False
        return True
