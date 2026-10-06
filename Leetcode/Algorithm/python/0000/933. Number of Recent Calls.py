class RecentCounter(object):

    def __init__(self):
        self.st = []

    def ping(self, t):
        while self.st and self.st[0] < t - 3000:
            self.st.pop(0)
        self.st.append(t)
        return len(self.st)
        


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
