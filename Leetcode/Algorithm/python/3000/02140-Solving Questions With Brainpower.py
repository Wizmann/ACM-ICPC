#!/bin/python3
from typing import *

class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        self.dp = [-1 for i in range(n)]

        return self.dfs(questions, 0)

    def dfs(self, questions, cur):
        if cur >= len(questions):
            return 0

        if self.dp[cur] != -1:
            return self.dp[cur]

        res = max(questions[cur][0] + self.dfs(questions, cur + questions[cur][1] + 1),
                  self.dfs(questions, cur + 1))
        
        self.dp[cur] = res
        return res

'''

^^^TEST^^^^
[[3,2],[4,3],[4,4],[2,5]]
-----
5
$$$TEST$$$

^^^TEST^^^
[[1,1],[2,2],[3,3],[4,4],[5,5]]
-------
7
$$$TEST$$$
'''


