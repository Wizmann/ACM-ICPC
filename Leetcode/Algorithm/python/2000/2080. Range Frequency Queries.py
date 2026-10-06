from collections import defaultdict

class RangeFreqQuery(object):

    def __init__(self, arr):
        self.g = defaultdict(list)
        for i, num in enumerate(arr):
            self.g[num].append(i)

    def query(self, left, right, value):
        a = self.lower_bound(self.g[value], right + 1)
        b = self.lower_bound(self.g[value], left)
        return a - b
    
    def lower_bound(self, nums, query):
        n = len(nums)
        l, r = 0, n - 1
        while l <= r:
            m = (l + r) / 2
            if nums[m] >= query:
                r = m - 1
            else:
                l = m + 1
        return l


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)
