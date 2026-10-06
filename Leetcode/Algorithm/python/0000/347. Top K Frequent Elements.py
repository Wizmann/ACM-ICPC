class Solution(object):
    def topKFrequent(self, nums, k):
        d = {}
        for num in nums:
            d[num] = d.get(num, 0) + 1
        return map(lambda x: x[0],
            sorted(d.items(), key=lambda y: y[1], reverse=True)[:k])
        