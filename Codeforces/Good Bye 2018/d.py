from itertools import permutations

def bruteforce(n):
    MOD = 998244353
    nums = []
    for p in permutations(range(1, n + 1)):
        nums += list(p)
    s = sum(range(1, n + 1))
    cnt = 0
    for i in xrange(len(nums)):
        if sum(nums[i: i + n]) == s:
            cnt += 1
    return cnt % MOD

'''
print bruteforce(3)
print bruteforce(4)
print bruteforce(5)
print bruteforce(6)
print bruteforce(7)
print bruteforce(8)
print bruteforce(9)
print bruteforce(10)
'''

def solve(n):
    MOD = 998244353
    u = reduce(lambda x, y: x * y % MOD, range(1, n + 1))
    pre = 3
    cur = 3
    for i in xrange(1, n + 1):
        cur = i * (pre - 1) % MOD
        pre = cur
    return (u * (n - 2) + cur) % MOD

n = int(raw_input())
print solve(n)
