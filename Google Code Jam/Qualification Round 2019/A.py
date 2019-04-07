def solve(ns):
    a, b = 0, 0
    for num in ns:
        num = int(num)
        if num == 0:
            a = a * 10
            b = b * 10
        elif num == 5:
            a = a * 10 + 2
            b = b * 10 + 3
        else:
            a = a * 10 + 1
            b = b * 10 + num - 1
            assert num - 1 != 4
    return a, b

def test(num):
    a, b = solve(str(num))
    assert a + b == int(num)
    assert '4' not in str(a)
    assert '4' not in str(b)

'''
test(940)
test(4)
test(4444)
for i in xrange(1, 9999):
    test(i)
    test(i ** 30)

test(123 * 99)
'''


T = int(raw_input())

for case_ in xrange(T):
    ns = raw_input()
    print 'Case #%d:' % (case_ + 1),
    print '%d %d' % solve(ns)
