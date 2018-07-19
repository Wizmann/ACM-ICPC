# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution(object):
    def rand10(self):
        while True:
            u = 0
            for i in xrange(4):
                u = (u << 1) + self.rand2() - 1
            if u <= 9:
                return u + 1

    def rand2(self):
        while True:
            a = rand7()
            if a <= 6:
                return (a - 1) % 2 + 1
