class Solution(object):
    def findKthPositive(self, arr, k):
        st = set(arr)
        i = 1
        cnt = 0
        while True:
            if i not in st:
                cnt += 1
                if cnt == k:
                    return i
            i += 1
        assert False
        return -1
