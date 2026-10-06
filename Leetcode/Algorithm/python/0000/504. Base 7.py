class Solution(object):
    def convertTo7(self, num):
        if num == 0:
            return '0'
            
        s = 1 if num >= 0 else -1
        num = abs(num)
        res = ''
        while num:
            res += str(num % 7)
            num /= 7
        res = res[::-1]
        if s < 0:
            res = '-' + res
        return res
