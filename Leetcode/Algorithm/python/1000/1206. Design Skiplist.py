INF = 10 ** 10
LEVEL = 5
P = 0.6

from random import random

class SkipListNode(object):
    def __init__(self, value):
        self.value = value
        self.next = [None for i in xrange(LEVEL)]

class Skiplist(object):
    def __init__(self):
        self.head = SkipListNode(-INF)
        
    def find(self, value):
        res = [None for i in xrange(LEVEL)]
        
        lv = LEVEL - 1
        cur = self.head
        while lv >= 0:
            assert cur.value <= value
            if cur.next[lv] == None or cur.next[lv].value > value:
                res[lv] = cur
                lv -= 1
            else:
                cur = cur.next[lv]
        return res            
        
    def search(self, target):
        p = self.find(target)
        return p[0].value == target

    def add(self, num):
        p = self.find(num)
        cur = SkipListNode(num)
        for i in xrange(LEVEL):
            p[i].next[i], cur.next[i] = cur, p[i].next[i]
            if random() < P:
                break
        
    def erase(self, num):
        if not self.search(num):
            return False
        p = self.find(num - 1)
        for i in xrange(LEVEL):
            if p[i].next[i] and p[i].next[i].value == num:
                p[i].next[i] = p[i].next[i].next[i]
        return True       


# Your Skiplist object will be instantiated and called as such:
# obj = Skiplist()
# param_1 = obj.search(target)
# obj.add(num)
# param_3 = obj.erase(num)
