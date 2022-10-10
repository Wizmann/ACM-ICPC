n = int(raw_input())

ta, tb, tc = 0, 0, 0
for i in xrange(n):
    a, b, c = map(int, raw_input().split())
    ta += a
    tb += b
    tc += c

if ta == 0 and tb == 0 and tc == 0:
    print 'YES'
else:
    print 'NO'

'''
^^^^^TEST^^^^
3
4 1 7
-2 4 -1
1 -5 -3
------------------
NO
$$$TEST$$$


^^^^^^^^^^TEST^^^^
3
3 -1 7
-5 2 -4
2 -1 -3
------------------
YES
$$$$$$$$TEST$$$
'''


