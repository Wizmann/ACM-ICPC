#python3
#coding=utf-8

import string

T = int(input())

for case_ in range(T):
    n = int(input())
    s = list(input())

    for c in string.ascii_uppercase:
        if c in s:
            break
    else:
        s.append('A')

    for c in string.ascii_lowercase:
        if c in s:
            break
    else:
        s.append('a')

    for c in string.digits:
        if c in s:
            break
    else:
        s.append('0')

    for c in '#@*&':
        if c in s:
            break
    else:
        s.append('#')

    while len(s) < 7:
        s.append('x')

    print("Case #%d: %s" % (case_ + 1, ''.join(s)))

'''
^^^^TEST^^^^
2
7
1234567
10
1111234567
-------
Case #1: 1234567aA&
Case #2: 1111234567@Rc
$$$$TEST$$$$


^^^^TEST^^^^
3
1
A
2
1*
7
1234aB&
-------
Case #1: Aa1*111
Case #2: 1*abAA*
Case #3: 1234aB&
$$$$TEST$$$$
'''
