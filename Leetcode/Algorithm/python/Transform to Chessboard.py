INF = 10 ** 10

class Solution(object):
    def movesToChessboard(self, board):
        n = len(board)
        
        ns = [int(''.join(map(str, line)), 2) for line in board]
        s = list(set(ns))
        if len(s) != 2:
            return -1
        
        pivot = s[0]
        remains = s[1]
        
        if (pivot & remains) != 0:
            return -1
        
        bits = int(''.join(['0' if i % 2 == 0 else '1' for i in xrange(n)]), 2)
        mask = (1 << n) - 1
        ms = int(''.join(['0' if item == pivot else '1' for item in ns]), 2)
        
        ans = INF
        for i in [bits, mask ^ bits]:
            for j in [bits, mask ^ bits]:
                if self.bitcount(ms ^ i) % 2 == 1 or self.bitcount(pivot ^ j) % 2 == 1:
                    continue
                ans = min(ans,
                          self.bitcount(ms ^ i) / 2 + self.bitcount(pivot ^ j) / 2)
        return -1 if ans == INF else ans
    
    def bitcount(self, num):
        return '{:b}'.format(num).count('1')
