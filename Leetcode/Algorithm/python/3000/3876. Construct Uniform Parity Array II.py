INF = 10 ** 10

class Solution(object):
    def uniformArray(self, nums1):
        min_odd = INF

        for num in nums1:
            if (num & 1) and num < min_odd:
                min_odd = num

        if min_odd == INF:
            return True

        for num in nums1:
            if not (num & 1) and num <= min_odd:
                return False

        return True
