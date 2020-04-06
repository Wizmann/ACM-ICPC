def solve(nums, base=0):
    #print nums, base
    mini = min(nums)

    res = '(' * (mini - base)

    pre = 0
    n = len(nums)

    for i in xrange(n + 1):
        if i == n:
            if i - pre > 0:
                res += solve(nums[pre: i], mini)
        elif nums[i] != mini:
            continue
        else:
            if i - pre > 0:
                res += solve(nums[pre: i], mini)
            pre = i + 1
            res += str(mini)
    res += ')' * (mini - base)
    return res

assert solve(map(int, '000111')) == '000(111)'
assert solve(map(int, '111000')) == '(111)000'
assert solve(map(int, '1321')) == '(1((3)2)1)'
assert solve(map(int, '221')) == '((22)1)'
assert solve(map(int, '021')) == '0((2)1)'
assert solve(map(int, '2')) == '((2))'
assert solve(map(int, '0000')) == '0000'
assert solve(map(int, '101')) == '(1)0(1)'

T = int(raw_input())

for case_ in xrange(T):
    nums = map(int, raw_input())
    res = solve(nums)

    print "Case #%d: %s" % (case_ + 1, res)
