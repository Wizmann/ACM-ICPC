# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.dp = {}
    
    def rectCover(self, number):
        if number == 0:
            return 0
        return self.solve(number)
    def solve(self, number):
        assert number >= 0
        if number == 0:
            return 1
        if number == 1:
            return 1
        if number in self.dp:
            return self.dp[number]
        self.dp[number] = self.solve(number - 1) + self.solve(number - 2)
        return self.dp[number]
