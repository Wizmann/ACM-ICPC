class Solution(object):
    def sumOfThree(self, num):
        base = (num - 3) / 3
        res = [base, base + 1, base + 2]
        if sum(res) == num:
            return res
        else:
            return []
