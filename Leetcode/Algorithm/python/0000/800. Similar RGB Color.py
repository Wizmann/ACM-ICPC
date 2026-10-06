class Solution(object):
    def similarRGB(self, color):
        (r1, g1, b1) = self.parse(color)
        return '#%02x%02x%02x' % (self.nn(r1), self.nn(g1), self.nn(b1))
    
    def parse(self, color):
        return int(color[1:3], 16), int(color[3:5], 16), int(color[5:7], 16)
    
    def nn(self, u):
        mini = 10 ** 10
        res = -1
        
        for i in xrange(0, 16):
            v = i * 16 + i
            if abs(u - v) < mini:
                mini = abs(u - v)
                res = v
        return res
