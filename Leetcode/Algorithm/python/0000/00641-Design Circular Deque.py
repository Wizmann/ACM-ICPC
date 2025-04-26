class MyCircularDeque(object):

    def __init__(self, k):
        self.size = 0
        self.queue = [None for i in xrange(k)]
        self.p = 0
        self.q = 0
        self.capacity = k
        
    def moveRight(self, pos):
        return (pos + 1) % self.capacity
    
    def moveLeft(self, pos):
        return (pos - 1 + self.capacity) % self.capacity

    def insertFront(self, value):
        if self.size + 1 > self.capacity:
            return False
        
        self.p = self.moveLeft(self.p)
        self.queue[self.p] = value
        self.size += 1
        return True        

    
    def insertLast(self, value):
        if self.size + 1 > self.capacity:
            return False
        
        self.queue[self.q] = value
        self.q = self.moveRight(self.q)
        self.size += 1  
        return True

    
    def deleteFront(self):
        if self.size - 1 < 0:
            return False
        
        self.p = self.moveRight(self.p)
        self.size -= 1
        return True

    
    def deleteLast(self):
        if self.size - 1 < 0:
            return False
        
        self.q = self.moveLeft(self.q)
        self.size -= 1
        return True
        

    def getFront(self):
        if self.size == 0:
            return -1
        return self.queue[self.p]
        

    def getRear(self):
        if self.size == 0:
            return -1
        q = self.moveLeft(self.q)
        return self.queue[q]
        

    def isEmpty(self):
        return self.size == 0
        

    def isFull(self):
        return self.size == self.capacity


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
