def num2axis(num):
    y = 1
    while num % (1 << y) == 0:
        y += 1
    x = (num - (1 << (y - 1))) / (1 << y) + 1
    return (y, x)

def axis2num(y, x):
    base = 1 << (y - 1)
    offset = (x - 1) * (1 << y)
    return base + offset

def get_max_y(n):
    res = 0
    while (1 << res) < n:
        res += 1
    return res

assert num2axis(4) == (3, 1)
assert num2axis(12) == (3, 2)
assert axis2num(3, 2) == 12
assert get_max_y(15) == 4
assert get_max_y(3) == 2

(n, q) = map(int, raw_input().split())
maxy = get_max_y(n)

for case_ in xrange(q):
    num = int(raw_input())
    path = raw_input()

    y, x = num2axis(num)

    for move in path:
        if move == 'L' and y > 1:
            x = x * 2 - 1
            y -= 1
        elif move == 'R' and y > 1:
            x = x * 2
            y -= 1
        elif move == 'U' and y < maxy:
            x = (x + 1) / 2
            y += 1

    print axis2num(y, x)
