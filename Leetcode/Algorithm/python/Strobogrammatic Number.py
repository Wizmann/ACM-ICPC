class Solution(object):
    def isStrobogrammatic(self, num):
        d = {
            '0': '0',
            '1': '1',
            '6': '9',
            '8': '8',
            '9': '6'
        }
        
        return map(lambda c: d.get(c, 'x'), str(num))[::-1] == list(str(num))
        
