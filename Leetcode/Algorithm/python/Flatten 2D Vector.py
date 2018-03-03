class Vector2D(object):

    def __init__(self, vec2d):
        self.vec2d = vec2d
        self.p = 0
        self.q = -1
        self.cur = None
        self.do_next()

    def next(self):
        cur = self.cur
        self.do_next()
        return cur

    def hasNext(self):
        return self.p < len(self.vec2d)
    
    def do_next(self):
        self.q += 1
        while self.p < len(self.vec2d):
            if self.q >= len(self.vec2d[self.p]):
                self.p += 1
                self.q = 0
            else:
                break
        if self.p < len(self.vec2d):
            self.cur = self.vec2d[self.p][self.q]
        
        

# Your Vector2D object will be instantiated and called as such:
# i, v = Vector2D(vec2d), []
# while i.hasNext(): v.append(i.next())
