# https://codeforces.com/problemset/problem/236/C
def gcd2(a, b):
    if a % b == 0:
        return b
    return gcd2(b, a % b)

def gcd(a, b, c):
    return gcd2(gcd2(a, b), c)

def lcm2(a, b):
    return a * b / gcd2(a, b)

def lcm(a, b, c):
    return lcm2(lcm2(a, b), c)

n = int(raw_input())
res = []
maxi = 0
for a in xrange(max(1, n - 10), n + 1):
    for b in xrange(a, n + 1):
        for c in xrange(b, n + 1):
            l = lcm(a, b, c)
            if l > maxi:
                res = [(a, b, c)]
                maxi = l
            elif l == maxi:
                res.append((a, b, c))
print maxi
