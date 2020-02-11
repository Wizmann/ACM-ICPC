# https://leetcode.com/problems/check-if-n-and-its-double-exist/

class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        if arr.count(0) >= 2:
            return True
        st = set(filter(lambda x: x, arr) )
        for num in arr:
            if 2 * num in st:
                return True
        return False
