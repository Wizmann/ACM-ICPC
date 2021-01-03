class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        n = len(arr)
        for i in range(n):
            pattern = arr[i: i + m]
            if pattern * k == arr[i: i + k * m]:
                return True
        return False
