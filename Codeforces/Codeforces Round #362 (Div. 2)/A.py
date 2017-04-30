class Solution(object):
    def __init__(self, t, s, x):
        self.t = t
        self.s = s
        self.x = x

    def solve(self):
        if self.x < self.t:
            return False
        if self.x == self.t:
            return True
        if self.x == self.t + 1 and self.x != self.t + self.s:
            return False
        return (self.x - self.t) % self.s == 0 or (self.x - 1 - self.t) % self.s == 0


assert Solution(3, 10, 4).solve() == False
assert Solution(3, 10, 3).solve() == True
assert Solution(3, 8, 51).solve() == True
assert Solution(3, 8, 52).solve() == True

if __name__ == '__main__':
    (t, s, x) = map(int, raw_input().split())
    print 'YES' if Solution(t, s, x).solve() else 'NO'
