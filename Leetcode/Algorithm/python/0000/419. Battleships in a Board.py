class Solution(object):
    def countBattleships(self, board):
        ans = 0
        n = len(board)
        if n == 0:
            return 0
        m = len(board[0])
        if m == 0:
            return 0
        
        ans = 0
        for i in xrange(n):
            for j in xrange(m):
                flag = True
                if board[i][j] == '.':
                    continue
                if 0 <= i - 1 < n and board[i - 1][j] == 'X':
                    flag = False
                if 0 <= j - 1 < m and board[i][j - 1] == 'X':
                    flag = False
                
                if flag:
                    ans += 1
        return ans
