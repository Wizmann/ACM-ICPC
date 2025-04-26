import string

class Solution(object):
    def isFascinating(self, n):
        m = str(n) + str(n * 2) + str(n * 3)
        return ''.join(sorted(m)) == '123456789'


'''
^^^^TEST^^^^
192
----------------
true
$$$$TEST$$$$

^^^^TEST^^^^
100
----------------
false
$$$$TEST$$$$

'''


