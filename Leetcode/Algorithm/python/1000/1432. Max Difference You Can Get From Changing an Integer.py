class Solution(object):
    def maxDiff(self, num):
        num = str(num)
        num1 = int(num.replace(*self.convertTo(num, '01', '1', '0')))
        num2 = int(num.replace(*self.convertTo(num, '9', '9', '9')))
        print num1, num2
        return num2 - num1
        
    def convertTo(self, num, value1, value2, value3):
        n = len(num)
        for i in xrange(n):
            if num[i] not in value1:
                if i == 0:
                   return (num[i], value2)
                else:
                   return (num[i], value3)
        return ('*', '*')
