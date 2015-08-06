import sys

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def lcm(a, b):
    return a / gcd(a, b) * b

def solve(n):
    d = {
        1: 1,
        2: 2,
        3: 6,
        4: 12,
    }
    if n in d:
        return d[n]
    return max(
        lcm(n * (n - 1), n - 2),
        lcm(n * (n - 1), n - 3),
        lcm((n - 1) * (n - 2), n - 3))
    
for line in sys.stdin:
    n = int(line)
    print solve(n)
