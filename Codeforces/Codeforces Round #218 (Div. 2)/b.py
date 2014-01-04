from fractions import gcd

def avail(a):
    ans = 0
    while a % 2 == 0:
        ans += 1
        a /= 2
    while a % 3 == 0:
        ans += 1
        a /= 3
    while a % 5 == 0:
        ans += 1
        a /= 5

    if a != 1:
        return -1
    else:
        return ans


(a, b) = map(int, raw_input().split())

c = gcd(a, b)

a /= c
b /= c

av = avail(a)
gv = avail(b)

if av != -1 and gv != -1:
    print av + gv
else:
    print -1
