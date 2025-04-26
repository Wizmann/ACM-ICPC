INF = 0x3f3f3f3f
class Solution(object):
    def findRestaurant(self, list1, list2):
        minidx = INF
        res = []
        d1 = dict(
            [ (v, k) for (k, v) in enumerate(list1) ]
        )
        for (idx, item) in enumerate(list2):
            if item not in d1:
                continue
            s = idx + d1[item]
            if s < minidx:
                res = [item]
                minidx = s
            elif s == minidx:
                res.append(item)
        return res
