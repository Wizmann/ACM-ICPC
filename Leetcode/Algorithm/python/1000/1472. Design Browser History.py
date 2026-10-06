class BrowserHistory(object):

    def __init__(self, homepage):
        self.history = [homepage]
        self.ptr = 0

    def visit(self, url):
        self.history = self.history[:self.ptr + 1]
        self.history.append(url)
        self.ptr += 1  
        assert len(self.history) == self.ptr + 1
        # print self.history, self.ptr

    def back(self, steps):
        self.ptr = max(0, self.ptr - steps)
        return self.history[self.ptr]
        

    def forward(self, steps):
        self.ptr = min(self.ptr + steps, len(self.history) - 1)
        return self.history[self.ptr]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
