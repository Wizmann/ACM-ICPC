class Solution(object):
    def numOfBurgers(self, t, c):
        x = t - 2 * c
        if x < 0 or x % 2 != 0:
            return []
        x /= 2
        
        y = c - x
        
        if x >= 0 and y >= 0 and 4 * x + 2 * y == t:
            return [x, y]
        else:
            return []
        
        
