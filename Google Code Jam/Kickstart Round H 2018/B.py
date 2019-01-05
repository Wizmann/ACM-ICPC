def solve(nums):
    n = len(nums)
    tot = sum(nums[:(n + 1) / 2])

    res = tot

    for i in xrange((n + 1) / 2, n):
        tot = tot + nums[i] - nums[i - (n + 1) / 2]
        res = max(res, tot)
    return res

assert solve(map(int, '1332')) == 6
assert solve(map(int, '9583')) == 14

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        print 'Case #%d: ' % (case_ + 1),
        n = int(raw_input())
        nums = map(int, raw_input())
        print solve(nums)

