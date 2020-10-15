#coding=utf-8

# 扩展欧几里得算法
def exgcd(a, b):
    if b == 0:
       return (a, 1, 0)
    (r, x, y) = exgcd(b, a % b)
    t = y
    y = x - (a / b) * y
    x = t
    return (r, x, y)

# 求乘法逆元，时间复杂度为O(logp)，p不需要为质数
def getInv(x, p):
    _, t, _ = exgcd(x, p)
    assert (x * t) % p == 1
    return (p + t % p) % p


# 线性求逆元，p为质数，且1 <= n <= p，时间复杂度为O(n)
def getInvFrom1ToN(n, p):
    inv = [0 for i in xrange(n + 1)]
    inv[1] = 1;
    for i in xrange(2, n + 1):
        inv[i] = (p - p / i) * inv[p % i] % p
        assert (i * inv[i]) % p == 1
    return inv


# 离线求逆元, p为质数，1 <= nums[i] <= p，时间复杂度为O(n + logp)
# 逆元是完全积性的，i.e. 前辍积的逆元 == 逆元的先辍积
# 所以可以计算出所有数的积的逆元，再分别与nums[1...n]相乘，逐步缩小前辍大小，直到解出所有的逆元
def getInvList(nums, p):
    # nums first index is 1
    n = len(nums) - 1
    s = [0 for i in xrange(n + 1)]
    sv = [0 for i in xrange(n + 1)]
    inv = [0 for i in xrange(n + 1)]
    s[0] = 1
    for i in xrange(1, n + 1):
        s[i] = s[i - 1] * nums[i] % p;
    sv[n] = pow(s[n], p - 2, p)
    for i in xrange(n, 0, -1):
        sv[i - 1] = sv[i] * nums[i] % p
    for i in xrange(1, n + 1):
        inv[i] = sv[i] * s[i - 1] % p
    return inv

