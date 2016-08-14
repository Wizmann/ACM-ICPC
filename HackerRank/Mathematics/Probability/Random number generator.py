def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

def solve(a, b, c):
    if c >= a + b:
        x = 1
        y = 1
    elif c >= max(a, b):
        x = 2 * a * b - (a + b - c) * (a + b - c)
        y = a * b * 2
    elif b <= c <= a:
        x = (c - b + c) * b
        y = a * b * 2
    elif a <= c <= b:
        x = (c - a + c) * a
        y = a * b * 2
    elif c <= min(a, b):
        x = c * c
        y = a * b * 2
    g = gcd(x, y)
    print '%d/%d' % (x / g, y / g)
    
if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        (a, b, c) = map(int, raw_input().split())
        solve(a, b, c)
