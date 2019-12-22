from collections import defaultdict
 
class Bag(object):
    def __init__(self):
        self.d = defaultdict(int)
 
    def add(self, c):
        self.d[c] += 1
        
    def remove(self, c):
        self.d[c] -= 1
 
    def equals(self, other):
        for (key, value) in other.d.items():
            if self.d[key] != value:
                #print key, self.d[key], value
                return False
        return True
    
 
def solve(a, b):
    if len(b) < len(a):
        return False
    b1 = Bag()
    for c in a:
        b1.add(c)
 
    b2 = Bag()
    n = len(a)
 
    for i in xrange(n):
        b2.add(b[i])
 
    if b2.equals(b1):
        return True
 
    for i in xrange(n, len(b)):
        b2.remove(b[i - n])
        b2.add(b[i])
        if b2.equals(b1):
            return True
    return False
 
assert solve('foo', 'f') == False
assert solve('foo', 'oof') == True
assert solve('a', 'oaof') == True
assert solve('ab', 'oaobf') == False
 
if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        sa = raw_input()
        sb = raw_input()
 
        print 'YES' if solve(sa, sb) else 'NO'
