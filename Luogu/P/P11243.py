#python3
#coding=utf-8
import re
import sys

if sys.version_info[0] == 3:
    raw_input = input
    xrange = range
    map_ = map
    def map(*args, **kwargs):
        return list(map_(*args, **kwargs))

T = int(raw_input())

for case_ in xrange(T):
    n = int(input())
    cmps = input()

    tot = 0
    for sub in cmps.split('>'):
        cur = 0
        pre = 0
        # print(re.split('<', sub))
        for eq in re.split('<', sub):
            if eq:
                cur += (len(eq) + 1) * pre
                pre += (len(eq) + 1)
            else:
                cur += pre
                pre += 1
        tot += cur
        # print('>>', cur)

    # print(tot)

    for sub in cmps.split('<'):
        cur = 0
        pre = 0
        # print(re.split('>', sub))
        for eq in re.split('>', sub):
            if eq:
                cur += (len(eq) + 1) * pre
                pre += (len(eq) + 1)
            else:
                cur += pre
                pre += 1
        tot += cur
        # print('<<', cur)

    print(tot)

'''
^^^^^^TEST^^^^
1
7
<=><=<
--------------
9
$$$$TEST$$$

^^^^^^TEST^^^^
5
5
<<<<
7
<=><=<
9
=<<><==<
11
>=<<=>>>=>
13
=><<=<=>=><>
-------------
10
9
13
29
25
$$$$TEST$$$
'''
