MOD = 10 ** 9 + 7

class Solution(object):
    def __init__(self):
        self.d = {}
    
    def knightDialer(self, N):
        ns = [1 for i in xrange(10)]
        return sum(self.solve(ns, N - 1)) % MOD
    
    def solve(self, ns, N):
        if N == 0:
            return ns
        if N == 1:
            return self.do_move(ns)
        a = self.solve(ns, N / 2)
        b = self.solve(a, N - N / 2)
        return b
    
    def do_move(self, ns):
        ms = [0 for i in xrange(10)]       
        nt = {
            0: [4, 6],
            1: [6, 8],
            2: [7, 9],
            3: [4, 8],
            4: [3, 9, 0],
            5: [],
            6: [1, 7, 0],
            7: [2, 6],
            8: [1, 3],
            9: [2, 4]
        }
        
        for i in xrange(10):
            for nxt in nt[i]:
                ms[nxt] = (ms[nxt] + ns[i]) % MOD
        return ms
        
