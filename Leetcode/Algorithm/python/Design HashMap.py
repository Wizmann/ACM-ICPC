class MyHashMap(object):

    def __init__(self):
        self.d = {}
        

    def put(self, key, value):
        self.d[key] = value
        

    def get(self, key):
        return self.d.get(key, -1)
        

    def remove(self, key):
        if key in self.d:
            del self.d[key]
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
