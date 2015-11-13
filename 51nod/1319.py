import sys
sys.stdin = open('input.txt')

def solve():
    x, n = map(int, raw_input().split())
    x = abs(x)

    ns = [int(raw_input()) for i in xrange(n)]
    s = sum(ns)
    
    if x == 0:
        return 0

    if x >= 2 * s:
        res = x / s * n
        x %= s
        for num in ns:
            if x <= 0:
                break
            res += 1
            x -= num
        return res
    else:
        l, r = -1, -1
        res = 0
        for num in ns + ns:
            if l < 0 or r < 0:
                l = r = num
            else:
                if l <= num <= r:
                    l = 0
                    r = r + num
                else:
                    l, r = min(abs(r - num), abs(l - num)), max(abs(r + num), abs(l + num))
            res += 1
            #print l, r, x
            if l <= x <= r:
                return res
        else:
            return 0

if __name__ == '__main__':
    T = int(raw_input()) 
    for case_ in xrange(T):
        print solve()
