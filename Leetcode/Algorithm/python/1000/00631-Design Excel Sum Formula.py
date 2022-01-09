class Excel(object):

    def __init__(self, H, W):
        W = self.char2int(W)
        self.matrix = [
            [0 for i in xrange(W + 1)]
            for j in xrange(H + 1)
        ]
        
    def char2int(self, c):
        return ord(c) - ord('A') + 1

    def set(self, r, c, v):
        c = self.char2int(c)
        self.matrix[r][c] = v

    def get(self, r, c):
        c = self.char2int(c)
        return self.do_get(r, c)
    
    def do_get(self, r, c):
        if isinstance(self.matrix[r][c], int):
            return self.matrix[r][c]
        else:
            return self.calc_sum(self.matrix[r][c])

    def sum(self, r, c, strs):
        c = self.char2int(c)
        res = self.calc_sum(strs)
        self.matrix[r][c] = strs
        return res
        
    def str2axis(self, s):
        return int(s[1:]), s[0]
    
    def calc_sum(self, l):
        res = 0
        for item in l:
            if ':' in item:
                ul, dr = item.split(':')
                res += self.do_sum(ul, dr)
            else:
                (rr, cc) = self.str2axis(item)
                res += self.get(rr, cc)
        return res
    
    def do_sum(self, ul, dr):
        y1, x1 = self.str2axis(ul)
        y2, x2 = self.str2axis(dr)
        x1 = self.char2int(x1)
        x2 = self.char2int(x2)
        
        res = 0
        for i in xrange(y1, y2 + 1):
            for j in xrange(x1, x2 + 1):
                res += self.do_get(i, j)
        print ul, dr, res
        return res
            

