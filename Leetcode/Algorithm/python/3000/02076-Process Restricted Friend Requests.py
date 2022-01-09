class DisjointSet(object):
    def __init__(self):
        self.father = {}
        
    def find_father(self, x):
        if self.father.get(x, x) == x:
            return x
        self.father[x] = self.find_father(self.father[x])
        return self.father[x]
    
    def make_union(self, x, y):
        fx = self.find_father(x)
        fy = self.find_father(y)
        self.father[fy] = fx

class Solution(object):
    def friendRequests(self, n, restrictions, requests):
        ds = DisjointSet()
        res = []
        cache = {}
        for (a, b) in requests:
            fa = ds.find_father(a)
            fb = ds.find_father(b)
            fa, fb = min(fa, fb), max(fa, fb)

            for (r1, r2) in restrictions:
                if r1 not in cache:
                    ra = ds.find_father(r1)
                    cache[r1] = ra
                else:
                    ra = cache[r1]
                if r2 not in cache:
                    rb = ds.find_father(r2)
                    cache[r2] = rb
                else:
                    rb = cache[r2]
                ra, rb = min(ra, rb), max(ra, rb)
                
                if (fa, fb) == (ra, rb):
                    res.append(False)
                    break
            else:
                ds.make_union(fa, fb)
                cache = {}
                res.append(True)
        return res
