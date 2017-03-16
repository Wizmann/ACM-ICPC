import string
nums = [
        ("ZERO", 0),
        ("SIX", 6),
        ("TWO", 2),
        ("EIGHT", 8),
        ("THREE", 3),
        ("FOUR", 4),
        ("FIVE", 5),
        ("SEVEN", 7),
        ("NINE", 9),
        ("ONE", 1),
    ]

class Solution(object):
    def __init__(self, s):
        self.s = s
        self.d = {}
        for c in self.s:
            self.d[c] = self.d.get(c, 0) + 1
        self.res = []
        self.remain = len(s)

    def solve(self):
        self.dfs(0)
        s = ''
        for (num, t) in self.res:
            s += str(num) * t
        return ''.join(sorted(s))

    def dfs(self, cur):
        #print cur, self.res
        if self.remain == 0:
            return True

        if cur == 10 and self.remain == 0:
            return True

        if cur == 10:
            return False

        num, digit = nums[cur]
        d1 = {}
        for c in num:
            d1[c] = d1.get(c, 0) + 1

        mini = 10 ** 10
        for i in string.uppercase:
            if i in d1:
                if self.d.get(i, 0) == 0:
                    mini = 0
                    break
                mini = min(mini, self.d[i] / d1[i])

        for i in xrange(mini, -1, -1):
            for j in string.uppercase:
                if j in d1 and i:
                    self.d[j] -= d1[j] * i
                    self.remain -= d1[j] * i
            self.res.append((digit, i))
            flag = self.dfs(cur + 1)
            if flag:
                return True
            self.res.pop()
            for j in string.uppercase:
                if j in d1 and i:
                    self.d[j] += d1[j] * i
                    self.remain += d1[j] * i

        return False


if __name__ == '__main__':
    assert Solution('ZERO').solve() == '0'
    assert Solution('OZONETOWER').solve() == '012'
    assert Solution('WEIGHFOXTOURIST').solve() == '2468'
    assert Solution('OURNEONFOE').solve() == '114'
    assert Solution('ETHER').solve() == '3'

    for case_ in xrange(10):
        import random
        s = ''
        ans = []
        for i in xrange(500):
            t = random.randint(0, 9)
            s += nums[t][0]
            ans.append(nums[t][1])

        assert Solution(s).solve() == ''.join(map(str, sorted(ans)))

    T = int(raw_input())
    for case_ in xrange(T):
        s = raw_input()
        print "Case #%d: %s" % (case_ + 1, Solution(s).solve())
