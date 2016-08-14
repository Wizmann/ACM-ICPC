import sys
sys.stdin = open('input.txt')

from math import sqrt

def toInt(x):
    if x == 0:
        return 0
    s = x / abs(x)
    x = abs(x)
    x = (x / 1000) * 1000
    return x * s

x, y, r = map(lambda s: int(float(s) * 1000), raw_input().split())

dx_l, dx_r = x - r, x + r
dy_l, dy_r = y - r, y + r

while dx_l % 1000 != 0:
    dx_l += 1

while dx_r % 1000 != 0:
    dx_r -= 1


while dy_l % 1000 != 0:
    dy_l += 1

while dy_r % 1000 != 0:
    dy_r -= 1

max_dis = 0
ansx, ansy = -1, -1
for dx in xrange(dx_l, dx_r + 1000, 1000):
    s = int(sqrt(r ** 2 - (dx - x) ** 2))
    dys = [toInt(y + s), toInt(y - s), toInt(y - s) + 1000]
    for dy in dys:
        dis = (dx - x) ** 2 + (dy - y) ** 2
        if dis > r * r:
            #print dx, dy, y - sqrt(r ** 2 - (dx - x) ** 2), dis, r * r
            continue
        if dis > max_dis:
            ansx, ansy = dx, dy
            max_dis = dis
        elif dis == max_dis and dx > ansx:
            ansx, ansy = dx, dy
            max_dis = dis
        elif dis == max_dis and dx == ansx and dy > ansy:
            ansx, ansy = dx, dy
            max_dis = dis
print ansx / 1000, ansy / 1000
assert ansx % 1000 == 0 and ansy % 1000 == 0
assert (ansx - x) ** 2 + (ansy - y) ** 2 <= r * r

