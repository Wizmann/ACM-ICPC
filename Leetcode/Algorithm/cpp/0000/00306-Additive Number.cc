class Solution(object):
    def isAdditiveNumber(self, num):
        self.st = []
        self.flag = False
        self.dfs(num)
        return self.flag
        
    def dfs(self, num):
        print self.st
        if not num and len(self.st) > 2:
            self.flag = True
        
        if self.flag == True:
            return
        
        n = len(num)
        for i in xrange(1, n + 1):
            u = num[:i]
            v = num[i:]
            if str(int(u)) != u:
                continue
            
            if len(self.st) < 2:
                self.st.append(int(u))
                self.dfs(v)
                self.st.pop()
            else:
                a = self.st[-1]
                b = self.st[-2]
                u = int(u)
                if a + b == u:
                    self.st.append(u)
                    self.dfs(v)
                    self.st.pop()
        
