import sys

def convert(a, b):
    res = []
    while b:
        res.append(b % a)
        b /= a
    return res + [0]

for line in sys.stdin:
    (a, b) = map(int, line.split())

    c = convert(a, b)

    g = 0

    flag = True
    for num in c:
        num = num + g
        if num in [-1, 0, 1]:
            g = 0
        elif num in [a - 1, a]:
            g = 1
        else:
            flag = False
            break

    if flag:
        print 'YES'
    else:
        print 'NO'
