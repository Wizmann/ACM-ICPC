class Solution(object):
    def grayCode(self, n):
        if n == 0:
            return [0]
        gray_code = ['0', '1']
        for i in xrange(1, n):
            gray_code = self.get_gray_code(gray_code)
        
        return map(lambda x: int(x, 2), gray_code)
        
    def get_gray_code(self, gray_code):
        a = map(lambda x: '0' + x, gray_code)
        b = map(lambda x: '1' + x, gray_code[::-1])
        return a + b
        
