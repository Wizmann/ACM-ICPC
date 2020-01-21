class Solution(object):
    def maximum69Number (self, num):
        num = str(num)
        num = num.replace('6', '9', 1)
        return int(num)
