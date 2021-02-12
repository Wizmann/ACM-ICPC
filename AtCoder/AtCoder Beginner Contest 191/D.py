#coding=utf-8

DIFF = 12345

def round_up(x):
    if x % 10000 == 0:
        return x
    else:
        return ((x / 10000) + 1) * 10000

def round_down(x):
    if x % 10000 == 0:
        return x
    else:
        return ((x / 10000) - 1) * 10000

def solve(x, y, r, iy, ey, dy):
    ll, rr = round_down(x - r - DIFF), round_up(x + r + DIFF)
    res = 0
    # print '>>', iy, ey
    while iy != ey:
        while ll <= rr:
            if (ll - x) ** 2 + (iy - y) ** 2 > r * r:
                ll += 10000
            else:
                break

        while ll <= rr:
            if (rr - x) ** 2 + (iy - y) ** 2 > r * r:
                rr -= 10000
            else:
                break
        # print ll, rr
        res += (rr - ll + 10000) / 10000
        iy += dy * 10000
    return res

def to_int(s):
    if '.' not in s:
        s += '0000'
        return int(s)
    s += '000000'
    s = list(s)
    while s[-5] != '.':
        s.pop()
    return int(''.join(s).replace('.', ''))
        

(x, y, r) = map(to_int, raw_input().split())

# print x, y, r

sy = round_up(y)

a = solve(x, y, r, sy, round_up(y + r + DIFF), +1)
b = solve(x, y, r, sy - 10000, round_down(y - r - DIFF), -1)
print a + b

'''
^^^TEST^^^
0.2 0.8 1.1
----
3
$$$TEST$$$

^^^TEST^^^
100 100 1
-----
5
$$$TEST$$$

^^^TEST^^^
42782.4720 31949.0192 99999.99
----
31415920098
$$$TEST$$$
'''
