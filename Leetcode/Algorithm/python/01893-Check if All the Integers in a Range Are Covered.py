class Solution(object):
    def isCovered(self, ranges, left, right):
        ranges.sort()
        l = ranges[0][0]
        r = ranges[0][1]
        new_ranges = []
        for (ll, rr) in ranges:
            if ll <= r + 1:
                r = max(r, rr)
            else:
                new_ranges.append((l, r))
                l, r = ll, rr
        new_ranges.append((l, r))
        # print new_ranges
        for (ll, rr) in new_ranges:
            if ll <= left and right <= rr:
                return True
        return False
