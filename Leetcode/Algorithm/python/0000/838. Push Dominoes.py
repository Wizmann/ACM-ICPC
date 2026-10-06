INF = 10 ** 10

class Solution(object):
    def pushDominoes(self, dominoes):
        n = len(dominoes)
        fs = [0 for i in xrange(n)]
        
        f = 0
        for i in xrange(n):
            if dominoes[i] == 'R':
                f = INF
            elif dominoes[i] == 'L':
                f = 0
            fs[i] += f
            if f > 0:
                f -= 1
            
        f = 0
        for i in xrange(n - 1, -1, -1):
            if dominoes[i] == 'L':
                f = -INF
            elif dominoes[i] == 'R':
                f = 0
            fs[i] += f
            if f < 0:
                f += 1
        
        return ''.join(map(self.mapping, fs))
    
    def mapping(self, u):
        if u == 0:
            return '.'
        elif u > 0:
            return 'R'
        else:
            return 'L'
