class Solution(object):
    def isPathCrossing(self, path):
        d = {
            'N': (0, -1),
            'E': (1, 0),
            'S': (0, 1),
            'W': (-1, 0)
        }
        
        cur = (0, 0)
        visited = set([cur])
        for p in path:
            y, x = cur
            my, mx = d[p]
            ny, nx = y + my, x + mx
            cur = (ny, nx)
            if cur in visited:
                return True
            visited.add(cur)
        return False
