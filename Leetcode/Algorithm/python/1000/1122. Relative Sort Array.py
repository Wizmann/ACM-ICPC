INF = 10 ** 10

class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        d = dict(map(lambda (idx, value): (value, idx), enumerate(arr2)))
        return sorted(arr1, key=lambda x: d.get(x, INF + x))
