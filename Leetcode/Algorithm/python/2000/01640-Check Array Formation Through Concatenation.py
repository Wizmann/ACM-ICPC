class Solution(object):
    def canFormArray(self, arr, pieces):
        n = len(arr)
        d = dict(zip(arr, range(n)))
        arr = map(lambda x: d[x], arr)
        for i, subarr in enumerate(pieces):
            pieces[i] = map(lambda x: d.get(x, -1), subarr)
        return arr == reduce(lambda x, y: x + y, sorted(pieces))
