class MyHashSet(object):

    def __init__(self):
        self.st = set()

    def add(self, key):
        self.st.add(key)
        

    def remove(self, key):
        if key in self.st:
            self.st.remove(key)
        

    def contains(self, key):
        return key in self.st        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
