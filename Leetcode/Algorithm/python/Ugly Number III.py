INF = 10 ** 20

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(*args):
    n = len(args)
    if n == 1:
        return args[0]
    elif n == 2:
        a, b = args
        return a * b / gcd(a, b)
    else:
        args = list(args)
        a = args.pop()
        b = args.pop()
        c = lcm(a, b)
        args.append(c)
        return lcm(*args)

class Solution(object):
    def nthUglyNumber(self, n, a, b, c):
        l, r = 0, INF
        while l <= r:
            m = (l + r) / 2
            cnt = 0
            
            cnt += m / a
            cnt += m / b
            cnt += m / c
            cnt -= m / lcm(a, b)
            cnt -= m / lcm(b, c)
            cnt -= m / lcm(a, c)
            cnt += m / lcm(a, b, c)
            
            if cnt >= n:
                r = m - 1
            else:
                l = m + 1
        return l
