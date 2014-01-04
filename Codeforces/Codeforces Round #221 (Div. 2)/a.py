#Result: 5502612     Dec 24, 2013 6:04:41 PM    Wizmann  A - Lever   Python 2   Accepted     312 ms  4200 KB
def calc(ss):
    res = 0
    p = 1
    for item in ss:
        if item != '=':
            t = int(item)
            res += t * p
        p += 1
    return res

s = raw_input()

(a, b) = s.split('^')

left = calc(a[::-1])
right = calc(b)

if left == right:
    print 'balance'
elif left > right:
    print 'left'
else:
    print 'right'
