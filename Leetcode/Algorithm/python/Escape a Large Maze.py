class Solution(object):
    def isEscapePossible(self, blocked, source, target):
        blocked = set(map(lambda (y, x): (y, x), blocked))
        return self.dfs(source, blocked, 12345) and self.dfs(target, blocked, 12345)
    
    def dfs(self, st, blocked, maxstep):
        self.visited = set()
        self.maxstep = maxstep
        return self.do_dfs(st, blocked)
    
    def do_dfs(self, st, blocked):
        if self.maxstep == 0:
            return True
        self.maxstep -= 1
        y, x = st
        self.visited.add((y, x))
        for (my, mx) in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ny = y + my
            nx = x + mx
            if (ny, nx) in self.visited:
                continue
            if (ny, nx) in blocked:
                continue
            if ny < 0 or nx < 0 or ny >= 10 ** 6 or nx >= 10 ** 6:
                continue
            if self.do_dfs((ny, nx), blocked):
                return True
        return False
