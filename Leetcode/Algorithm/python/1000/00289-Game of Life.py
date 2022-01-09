my = [-1, -1, -1, 0, 0, 1, 1, 1]
mx = [-1, 0, 1, -1, 1, -1, 0, 1]
M = 8

class Solution(object):
    def gameOfLife(self, board):
        n = len(board)
        if n == 0:
            return
        m = len(board[0])
        if m == 0:
            return
        
        for i in xrange(n):
            for j in xrange(m):
                cnt = 0
                for k in xrange(M):
                    ny = i + my[k]
                    nx = j + mx[k]
                    
                    if 0 <= ny < n and 0 <= nx < m and board[ny][nx] & 1:
                        cnt += 1
                        
                if board[i][j] and cnt in [2, 3]:
                    board[i][j] |= 2
                elif not board[i][j] and cnt == 3:
                    board[i][j] |= 2
        
        for i in xrange(n):
            for j in xrange(m):
                board[i][j] >>= 1
        
                    
