(l1, r1, l2, r2) = map(int, raw_input().split())

if l1 > l2:
    l1, r1, l2, r2 = l2, r2, l1, r1

if r2 < r1:
    print r2 - l2
else:
    print max(0, r1 - l2)

'''
^^^^TEST^^^^
0 3 1 5
-----
2
$$$TEST$$$$

^^^^TEST^^^^
0 10 1 5
-----
4
$$$TEST$$$$


^^^^TEST^^^
0 1 4 5
------
0
$$$TEST$$$$


^^^^TEST^^^
0 3 3 7
------
0
$$$TEST$$$$
'''
