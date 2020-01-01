my = [0, 1, 1]
mx = [1, 0, 1]
INF = 10 ** 10
MOD = (10 ** 9) + 7
class Solution(object):
    def pathsWithMaxScore(self, board):
        n = len(board)
        m = len(board[0])
        d = {}
        d[(0, 0)] = [0, 1]
        def getScore(y, x):
            if board[y][x] in 'SE':
                return 0
            else:
                return int(board[y][x])
        for i in xrange(n):
            for j in xrange(m):
                key = (i, j)
                if key not in d or d[key][1] < 0:
                    continue
                for (dy, dx) in zip(my, mx):
                    ny = dy + i
                    nx = dx + j
                    
                    if ny < 0 or ny >= n or nx < 0 or nx >= m:
                        continue
                    
                    if board[ny][nx] == 'X':
                        d[(ny, nx)] = [-INF, -INF]
                        continue
                    #print d
                    (score, cnt) = d[key]
                    
                    if (ny, nx) not in d:
                        d[(ny, nx)] = [-1, -1]
                    ns = score + getScore(ny, nx)
                    if d[(ny, nx)][0] == ns:
                        d[(ny, nx)][1] += cnt
                    else:
                        d[(ny, nx)] = max(d[(ny, nx)], [ns, cnt % MOD])
        score, cnt = d.get((n - 1, m - 1), [-INF, -INF])
        if cnt <= 0:
            return [0, 0]
        return [score, cnt % MOD]
