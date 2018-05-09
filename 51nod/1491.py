from math import sqrt
N = 100011

def calc(s):
    n = len(s)
    res = [0 for i in xrange(N)]
    for i in xrange(n):
        u = int(s[i])
        if u == 1:
            v = n - 1 - i
            res[v] = 1
    return res
    
if __name__ == '__main__':
    a = calc(raw_input().strip())
    b = calc(raw_input().strip())

    g1, g2 = 0, 0
    for i in xrange(N - 1, 1, -1):
        g = a[i] - b[i] + g1
        if g >= 2:
            print '>'
            exit(0)
        elif g <= -2:
            print '<'
            exit(0)
        g1, g2 = g2 + g, g

    a[1] += g1
    a[0] += g2

    g = (a[1] - b[1]) * (sqrt(5) + 1) / 2 + a[0] - b[0]

    if g > 0:
        print '>'
    elif g < 0:
        print '<'
    else:
        print '='
