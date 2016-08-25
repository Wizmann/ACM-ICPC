MAXI = 2 * (10 ** 10)

def sign(x):
    return 1 if x >= 0 else -1

def cstyle_int(x):
    if x == 0:
        return 0
    s = 1 if x >= 0 else -1
    x = abs(x)
    return s * int(x)

def exgcd(a, b):
    if b == 0:
       return (a, 1, 0)
    (r, x, y) = exgcd(b, a % b)
    t = y
    y = x - (a / b) * y
    x = t
    return (r, x, y)

def solve(a1, b1, a2, b2, L, R):
    a, b, c = a2, b2 - b1, a1
    llx = sign(L - b1 + a1 - 1) * abs(L - b1 + a1 - 1) / a1
    rrx = sign(R - b1) * abs(R - b1) / a1

    if rrx < 0:
        return 0

    llx = max(llx, 0)
    rrx = max(rrx, 0)


    lly = sign(L - b2 + a2 - 1) * abs(L - b2 + a2 - 1) / a2
    rry = sign(R - b2) * abs(R - b2) / a2

    if rry < 0:
        return 0

    lly = max(lly, 0)
    rry = max(rry, 0)

    ll = c * llx - b
    rr = c * rrx - b

    ll = sign(ll + a - 1) * abs(ll + a - 1) / a
    rr = sign(rr) * abs(rr) / a

    ll = max(lly, ll)
    rr = min(rry, rr)
    #print rr, ll

    (r, w, v) = exgcd(a1, a2)
    w = -w


    if (b1 - b2) % r != 0:
        return 0
    else:
        base1 = (b1 - b2) / r * w * a1 + b1 
        base2 = (b1 - b2) / r * v * a2 + b2 
        assert base1 == base2
        base = base1

        lcm = a1 * a2 / r
        #print base, lcm
        #print '>>', ll, rr, (rr * a2 + b2), (ll * a2 + b2)
        base -= (base / lcm + 1) * lcm
        while base > 0:
            base -= lcm
        #print (rr * a2 + b2 - base) / lcm , (ll * a2 + b2 - 1 - base) / lcm
        ans = (rr * a2 + b2 - base) / lcm - (ll * a2 + b2 - 1 - base) / lcm
        return max(0, ans)

def brute_force(a1, b1, a2, b2, L, R):
    i = 0
    sa, sb = set(), set()
    while a1 * i + b1 <= R:
        if a1 * i + b1 >= L:
            sa.add(a1 * i + b1)
        i += 1

    i = 0
    while a2 * i + b2 <= R:
        if a2 * i + b2 >= L:
            sb.add(a2 * i + b2)
        i += 1
    return len(sa & sb)


def test(*args):
    assert solve(*args) == brute_force(*args)

assert solve(2, 4, 3, 0, 6, 17) == 2
assert solve(2, 0, 3, 3, 5, 21) == 3
assert solve(2, 0, 3, 3, 5, 21) == brute_force(2, 0, 3, 3, 5, 21)
test(4, 2, 4, 4, 8, 200)
test(9, 2, 4, 4, 8, 200)
test(9, -2, 4, 4, 8, 200)
test(9, -2, 4, 4, -100, 200)
test(1412412, -112312, 3123412, 12313, -100, 200)
test(1, 0, 1, 0, -100, 200)
test(1, 0, 1, 0, 1, 1)
test(2, 0, 1, 0, 1, 1)
test(3, 8, 6, 8, -6, 0)

'''
import random
for i in xrange(10000):
    a1 = random.randint(1, 10)
    a2 = random.randint(1, 10)
    b1 = random.randint(-10, 10)
    b2 = random.randint(-10, 10)
    L = random.randint(-10, 10)
    R = random.randint(-10, 10)
    L, R = min(L, R), max(L, R)
    print a1, b1, a2, b2, L, R
    test(a1, b1, a2, b2, L, R)

test(967, 339, 632, 339, -828, -275)

print 'OK'

'''

if __name__ == '__main__':
    (a1, b1, a2, b2, L, R) = map(int, raw_input().split())
    print solve(a1, b1, a2, b2, L, R)
