BITS = 64

class Solution(object):
    def queryString(self, S, N):
        self.st = set()
        for i in xrange(1, BITS + 1):
            self.get_nums(S, i)
            #print self.st
        for i in xrange(1, N + 1):
            if i not in self.st:
                return False
        return True
    
    def get_nums(self, S, wnd):
        cur = 0
        if len(S) < wnd:
            return
        for i in xrange(wnd):
            cur = cur * 2 + int(S[i])
        self.st.add(cur)
        
        for i in xrange(wnd, len(S)):
            cur = (cur * 2) & ((1 << wnd) - 1)
            cur = cur + int(S[i])
            self.st.add(cur)
        
        
