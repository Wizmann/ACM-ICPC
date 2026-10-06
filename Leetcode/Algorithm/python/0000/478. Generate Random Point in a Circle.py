import math
import random

class Solution(object):

    def __init__(self, radius, x_center, y_center):
        self.r = radius
        self.x = x_center
        self.y = y_center

    def randPoint(self):
        d = random.uniform(0, 2 * math.pi)
        r = math.sqrt(random.uniform(0, 1)) * self.r
        
        x = r * math.cos(d) + self.x
        y = r * math.sin(d) + self.y
        
        assert (self.x - x) ** 2 + (self.y - y) ** 2 <= self.r ** 2
        
        return (x, y)
        
        

