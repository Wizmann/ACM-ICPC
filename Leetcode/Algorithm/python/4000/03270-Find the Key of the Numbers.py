class Solution(object):
    def generateKey(self, num1, num2, num3):
        nums = map(str, [num1, num2, num3])
        res = ''
        for i in xrange(-4, 0):
            d = min(map(lambda num: int(('00000' + num)[i]), nums))
            res += str(d)
        return int(res)
