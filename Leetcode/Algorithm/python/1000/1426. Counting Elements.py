class Solution(object):
    def countElements(self, arr):
        st = set(arr)
        return len([x for x in arr if x + 1 in st])
