from collections import deque

class FrontMiddleBackQueue(object):

    def __init__(self):
        self.q1 = deque()
        self.q2 = deque()

    def pushFront(self, val):
        self.q1.appendleft(val)
        self.adjust()

    def pushMiddle(self, val):
        self.q1.append(val)
        self.adjust()

    def pushBack(self, val):
        self.q2.append(val)
        self.adjust()

    def popFront(self):
        if not self.q1 and not self.q2:
            return -1
        if self.q1:
            u = self.q1.popleft()
        else:
            u = self.q2.popleft()
        self.adjust()
        return u

    def popMiddle(self):
        if not self.q1 and not self.q2:
            return -1
        # print self.q1, self.q2
        if len(self.q1) == len(self.q2):
            u = self.q1.pop()
        else:
            u = self.q2.popleft()
        self.adjust()
        return u

    def popBack(self):
        if not self.q1 and not self.q2:
            return -1
        if self.q2:
            u = self.q2.pop()
        elif self.q1:
            u = self.q1.pop()
        self.adjust()
        return u
        
    def adjust(self):
        n = len(self.q1) + len(self.q2)
        n1 = n / 2
        n2 = n - n1
        while len(self.q1) > n1:
            u = self.q1.pop()
            self.q2.appendleft(u)
        while len(self.q1) < n1:
            u = self.q2.popleft()
            self.q1.append(u)
        

# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()
