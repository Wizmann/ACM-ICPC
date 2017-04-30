import re

def remove_leading_zero(s):
    n = len(s)
    ptr = 0
    while ptr < n:
        if s[ptr] != '0':
            break
        ptr += 1

    if ptr == n:
        return '0'
    else:
        return s[ptr:]

assert remove_leading_zero('0') == '0'
assert remove_leading_zero('00') == '0'
assert remove_leading_zero('002') == '2'
assert remove_leading_zero('0020') == '20'

def remove_trailing_zero(s):
    s = list(s)
    while s and s[-1] == '0':
        s.pop()
    return ''.join(s)

class Solution(object):
    def __init__(self, s):
        g = re.search("^(\d+)\.(\d+)e(\d+)$", s)
        self.a, self.b, self.d = g.groups()

    def solve(self):
        ptr = 0
        n = len(self.b)
        for i in xrange(int(self.d)):
            if ptr >= n:
                self.a += '0'
            else:
                self.a += self.b[ptr]
                ptr += 1

        if ptr == n:
            return remove_leading_zero(self.a)
        else:
            self.b = remove_trailing_zero(self.b[ptr:])
            if self.b:
                return remove_leading_zero(self.a) + '.' + self.b
            else:
                return remove_leading_zero(self.a)


assert Solution('0.000e1').solve() == '0'
assert Solution('8.549e2').solve() == '854.9'
assert Solution('8.549e3').solve() == '8549'
assert Solution('8.549e4').solve() == '85490'
assert Solution('0.33e0').solve() == '0.33'
assert Solution('0.033e1').solve() == '0.33'
assert Solution('0.000e1').solve() == '0'

if __name__ == '__main__':
    s = raw_input()
    print Solution(s).solve()
