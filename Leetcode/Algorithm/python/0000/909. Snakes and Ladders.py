INF = 10 ** 10

class Solution(object):
    def init(self, board):
        self.board = board[::-1]
        self.d = {}

    def snakesAndLadders(self, board):
        self.init(board)
        n = len(self.board)
        m = len(self.board[0])
        self.q = [0]
        self.dis = [INF for i in xrange(n * m)]
        self.dis[0] = 0
        while self.q:
            cur = self.q.pop(0)
            self.solve(cur)
        res = self.dis[n * m - 1]
        if res >= INF:
            return -1
        return res
    
    def solve(self, cur):
        n = len(self.board)
        m = len(self.board[0])

        if self.dis[cur] >= self.dis[n * m - 1]:
            return
        for i in xrange(1, 7):
            nxt = cur + i
            if nxt >= m * n:
                continue
            y, x = self.index_to_pos(nxt)
            if self.board[y][x] != -1:
                jmp = self.board[y][x] - 1
                if self.dis[jmp] > self.dis[cur] + 1:
                    self.dis[jmp] = self.dis[cur] + 1
                    self.q.append(jmp)
            else:
                if self.dis[nxt] > self.dis[cur] + 1:
                    self.dis[nxt] = self.dis[cur] + 1
                    self.q.append(nxt)
    
    def pos_to_index(self, x, y):
        n = len(self.board)
        m = len(self.board[0])
        if y % 2 == 0:
            return y * m + x
        else:
            return y * m + (m - x)
        
    def index_to_pos(self, cur):
        n = len(self.board)
        m = len(self.board[0])
        y = cur / m
        if y % 2 == 0:
            return y, cur % m
        else:
            return y, (m - 1) - (cur % m)
