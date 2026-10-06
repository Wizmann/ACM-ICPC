class Solution(object):
    def largestOddNumber(self, num):
        num = list(num)
        while num and int(num[-1]) % 2 == 0:
            num.pop()
        return ''.join(num)
