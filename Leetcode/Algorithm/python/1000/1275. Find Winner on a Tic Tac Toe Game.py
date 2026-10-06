class Solution(object):
    def tictactoe(self, moves):
        self.grid = [ ['S', 'S', 'S'], ['S', 'S', 'S'], ['S', 'S', 'S'] ]
        for i, (y, x) in enumerate(moves):
            player = 'A' if i % 2 == 0 else 'B'
            self.grid[y][x] = player
            if self.check(player):
                return player
        return "Pending" if len(moves) < 9 else "Draw"
            
        
    def check(self, player):
        for i in xrange(3):
            cnt = 0
            for j in xrange(3):
                if self.grid[i][j] == player:
                    cnt += 1
            if cnt == 3:
                return True
            
        for i in xrange(3):
            cnt = 0
            for j in xrange(3):
                if self.grid[j][i] == player:
                    cnt += 1
            if cnt == 3:
                return True
            
        cnt = 0
        for i in xrange(3):
            if self.grid[i][i] == player:
                cnt += 1
        if cnt == 3:
            return True
        
        cnt = 0
        for i in xrange(3):
            if self.grid[i][2 - i] == player:
                cnt += 1
        if cnt == 3:
            return True
        
        return False
