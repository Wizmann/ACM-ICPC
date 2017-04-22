def remove_leading_zeros(s):
    if not s:
        return ''
    s = list(s[::-1])
    while s and s[-1] == '0':
        s.pop()
    res = ''.join(s[::-1])
    if not res:
        return '0'
    return res
    
assert remove_leading_zeros('1111') == '1111'
assert remove_leading_zeros('0000') == '0'
assert remove_leading_zeros('000001111') == '1111'
assert remove_leading_zeros('011110') == '11110'


def solve(num):
    INF = 10 ** 10
    ns = map(int, num)
    
    if sum(ns) % 3 == 0:
        return num

    r = sum(ns) % 3
    t = 1 if r == 2 else 2

    d = {0: [], 1: [], 2: []}

    for i, c in enumerate(ns):
        d[c % 3].append(i)

    d[1] = d[1][::-1]
    d[2] = d[2][::-1]

    res1, res2 = '', ''
    for i in d[r]:
        res1 = num[:i] + num[i + 1:]
        res1 = remove_leading_zeros(res1)
        break

    for i in xrange(1, len(d[t])):
        b, a = d[t][i - 1], d[t][i]

        res2 = num[:a] + num[a + 1:b] + num[b + 1:]
        res2 = remove_leading_zeros(res2)
        break

    if res1 or res2:
        if len(res1) > len(res2):
            return res1
        else:
            return res2
    else:
        return '-1'
        
def brute_force(s):
    res = -1
    n = len(s)
    
    if sum(map(int, s)) % 3 == 0:
        return s

    for i in xrange(n):
        t = s[:i] + s[i + 1:]
        if t and sum(map(int, t)) % 3 == 0:
            res = max(res, int(t))
            
    for i in xrange(n):
        for j in xrange(i + 1, n):
            t = s[:i] + s[i + 1:j] + s[j + 1:]
            if t and sum(map(int, t)) % 3 == 0:
                res = max(res, int(t))
    return str(res)


assert solve('1102') == '102'

assert solve('1103') == '3'
assert solve('1033') == '33'
assert solve('10') == '0'
assert solve('11') == '-1'
assert solve('1110') == '1110'
assert solve('111') == '111'


assert solve('0') == '0'
assert solve('1') == '-1'
assert solve('2') == '-1'
assert solve('7') == '-1'
assert solve('9') == '9'

import random

for i in xrange(1, 3000):
    a = solve(str(i))
    b = brute_force(str(i))

    if a != '-1':
        #print i, a, b
        assert sum(map(int, b)) % 3 == 0
        assert sum(map(int, a)) % 3 == 0
        assert len(a) == len(b)
    else:
        assert b == '-1'


if __name__ == '__main__':
    s = raw_input()
    print solve(s)
