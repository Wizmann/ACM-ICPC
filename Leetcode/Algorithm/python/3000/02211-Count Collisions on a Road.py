class Solution(object):
    def countCollisions(self, directions):
        st = []
        directions = list(directions)
        n = len(directions)
        res = 0
        
        for i in xrange(n - 2, -1, -1):
            c = directions[i]
            if c != 'R':
                continue
            if directions[i + 1] == 'S':
                directions[i] = 'S'
                res += 1
            if directions[i + 1] == 'L':
                directions[i] = 'S'
                directions[i + 1] = 'S'
                res += 2
                
        for i in xrange(1, n):
            c = directions[i]
            if c != 'L':
                continue
            if directions[i - 1] == 'S':
                directions[i] = 'S'
                res += 1
            if directions[i - 1] == 'R':
                directions[i] = 'S'
                directions[i - 1] = 'S'
                res += 2
        return res
                
        
                
