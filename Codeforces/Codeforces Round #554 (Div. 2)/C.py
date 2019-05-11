def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def solve(a, b):
    a, b = min(a, b), max(a, b)

    maxi = a * b / gcd(a, b)
    maxk = 0

    delta = b - a
    i = 1
    factors = set()
    while i * i <= delta:
        if delta % i == 0:
            factors.add(i)
            factors.add(delta / i)
        i += 1

    factors = sorted(factors)

    for f in factors:
        u = f - a % f
        l = (a + u) * (b + u) / gcd(a + u, b + u)
        if l < maxi:
            maxi = l
            maxk = u
    return maxk

assert solve(6, 10) == 2
assert solve(21, 31) == 9
assert solve(5, 10) == 0

if __name__ == '__main__':
    a, b = map(int, raw_input().split())
    print solve(a, b)
