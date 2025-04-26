class DisjointSet(object):
    def __init__(self):
        self.father = {}
        
    def find_father(self, x):
        if x not in self.father:
            self.father[x] = x
            return x
        
        if self.father[x] == x:
            return x
        f = self.find_father(self.father[x])
        self.father[x] = f
        return f
    
    def make_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        self.father[fb] = fa

class Solution(object):
    def equationsPossible(self, equations):
        ds = DisjointSet()
        eq = []
        ne = []
        for expr in equations:
            a, b = expr[0], expr[-1]
            oph = expr[1:-1]
            if oph == '==':
                eq.append((a, b))
            else:
                ne.append((a, b))
        for (a, b) in eq:
            fa = ds.find_father(a)
            fb = ds.find_father(b)
            ds.make_union(fa, fb)
            
        for (a, b) in ne:
            fa = ds.find_father(a)
            fb = ds.find_father(b)
            if fa == fb:
                return False
        return True
