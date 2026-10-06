import re

class StringIterator(object):

    def __init__(self, compressedString):
        tokens = filter(lambda x: x, re.split(r"(\d+)", compressedString))
        self.s = []

        m = len(tokens)
        for i in xrange(0, m, 2):
            c = tokens[i]
            u = int(tokens[i + 1])
            self.s.append([c, u])

        self.ptr = 0

    def next(self):
        while self.ptr < len(self.s):
            (c, u) = self.s[self.ptr]
            if u <= 1:
                self.ptr += 1
            else:
                self.s[self.ptr][1] -= 1
            return c
        else:
            return ' '

    def hasNext(self):
        return self.ptr < len(self.s)

        
s1 = StringIterator("a1b2")
assert s1.s == [ ['a', 1], ['b', 2] ]

s2 = StringIterator("a1b2")
assert s2.next() == 'a'
assert s2.next() == 'b'
assert s2.next() == 'b'
assert s2.hasNext() == False
assert s2.next() == ' '
assert s2.hasNext() == False


# Your StringIterator object will be instantiated and called as such:
# obj = StringIterator(compressedString)
# param_1 = obj.next()
# param_2 = obj.hasNext()

