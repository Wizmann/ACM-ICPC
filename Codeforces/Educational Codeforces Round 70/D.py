def solve1(s):
    s = map(int, list(s))
    dp = [0, 0, 0, 0]
    for num in s:
        dp2 = dp[:]
        if num == 1:
            dp2[0] += 1
        elif num == 3:
            dp2[1] += dp[0]
            dp2[2] += dp[1]
        elif num == 7:
            dp2[3] += dp[2]
        else:
            assert False
        dp = dp2
    return dp[3]

assert solve1('113337') == 6
assert solve1('1337') == 1

def solve2(num):
    for i in xrange(2, 123456):
        b = i * (i - 1) / 2
        c = num / b
        if c == 0:
            continue
        rem = num - b * c
        if 3 + rem + i - 2 + c > 10 ** 5:
            continue
        res = '133' + (rem * '7') + ((i - 2) * '3') + (c * '7')
        assert solve1(res) == num
        return res

T = int(raw_input())
for case_ in xrange(T):
    num = int(raw_input())
    print solve2(num)


