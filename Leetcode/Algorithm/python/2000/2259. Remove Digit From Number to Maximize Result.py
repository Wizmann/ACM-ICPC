class Solution(object):
    def removeDigit(self, number, digit):
        number = number
        digit = digit
        res = -1
        for i, num in enumerate(number):
            if num == digit:
                s = int(number[:i] + number[i + 1:])
                res = max(res, int(s))
        return str(res)
