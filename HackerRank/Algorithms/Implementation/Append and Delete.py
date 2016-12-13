class Solution(object):
    def __init__(self, a, b, k):
        self.a = a
        self.b = b
        self.k = k

    def common_prefix(self, a, b):
        res = 0
        l = min(len(a), len(b))
        for i in xrange(l):
            if a[i] == b[i]:
                res += 1
            else:
                break
        return res

    def solve(self):
        p = self.common_prefix(self.a, self.b)
        step = len(self.a) + len(self.b) - 2 * p
        if step > self.k:
            return False
        elif (self.k - step) % 2 == 0:
            return True
        elif p == 0 or len(self.b) + len(self.a) <= self.k:
            return True
        else:
            return False

assert Solution('abc', 'ab', 1).solve() == True
assert Solution('abc', 'abcd', 1).solve() == True
assert Solution('abc', 'abcd', 2).solve() == False
assert Solution('abc', 'abdd', 2).solve() == False
assert Solution('abc', 'abdd', 3).solve() == True
assert Solution('hackerhappy', 'hackerrank', 9).solve() == True
assert Solution('aba', 'aba', 7).solve() == True

if __name__ == '__main__':
    a = raw_input()
    b = raw_input()
    k = int(raw_input())

    print 'Yes' if Solution(a, b, k).solve() else 'No'
