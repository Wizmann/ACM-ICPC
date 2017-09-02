SIZE = 1234567

class Solution(object):
    def __init__(self, s):
        self.s = s

    def solve(self):
        n = len(self.s) + 100
        self.dp = [0 for i in xrange(n * 2)]
        ptr = n

        ans = 0
        for c in self.s:
            if c == '(':
                ptr -= 1
                self.dp[ptr + 1] += 1
            else:
                ptr += 1
                self.dp[ptr - 1] = 0
                ans += self.dp[ptr]
        return ans

assert Solution("(").solve() == 0
assert Solution(")").solve() == 0
assert Solution("()").solve() == 1
assert Solution("())").solve() == 1
assert Solution("()()").solve() == 3
assert Solution("(()").solve() == 1
assert Solution("(())").solve() == 2

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        s = raw_input().strip()
        print Solution(s).solve()
