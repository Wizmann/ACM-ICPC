class LUPrefix(object):

    def __init__(self, n):
        self.st = set()
        self.ptr = 0
        self.n = n

    def upload(self, video):
        self.st.add(video)
        while self.ptr + 1 in self.st:
            self.ptr += 1
        

    def longest(self):
        return self.ptr
        


# Your LUPrefix object will be instantiated and called as such:
# obj = LUPrefix(n)
# obj.upload(video)
# param_2 = obj.longest()
