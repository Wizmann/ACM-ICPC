class Solution(object):
    def numRookCaptures(self, board):
        n = len(board)
        m = len(board[0])
        
        y, x = -1, -1
        for i in xrange(n):
            for j in xrange(m):
                if board[i][j] == 'R':
                    y, x = i, j

        ans = 0
        for (my, mx) in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            cy, cx = y, x
            while True:
                if cy < 0 or cy >= n or cx < 0 or cx >= m:
                    break
                if board[cy][cx] == 'p':
                    ans += 1
                    break
                if board[cy][cx] not in 'R.,':
                    break
                cy += my
                cx += mx
        return ans
