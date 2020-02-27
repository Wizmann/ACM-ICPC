# https://leetcode.com/problems/validate-binary-tree-nodes/

from typing import *

INF = 10 ** 10

class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        st = set(leftChild + rightChild)
        if -1 not in st:
            return False
        st.remove(-1)
        st ^= set(range(n))
        if len(st) != 1:
            return False
        root = list(st)[0]
        visited = [False for i in range(n)]
        return self.dfs(root, leftChild, rightChild, visited) == n

    def dfs(self, cur, left, right, visited):
        if cur == -1:
            return 0
        if visited[cur]:
            return -INF
        visited[cur] = True
        res = 1
        res += self.dfs(left[cur], left, right, visited)
        res += self.dfs(right[cur], left, right, visited)
        return res

S = Solution()

assert S.validateBinaryTreeNodes(1, [-1], [-1]) == True
assert S.validateBinaryTreeNodes(1, [1], [-1]) == False
assert S.validateBinaryTreeNodes(2, [-1, 1], [-1, -1]) == False
assert S.validateBinaryTreeNodes(2, [-1, 0], [-1, -1]) == True
assert S.validateBinaryTreeNodes(2, [-1, -1], [-1, -1]) == False
assert S.validateBinaryTreeNodes(2, [1, 0], [-1, -1]) == False
