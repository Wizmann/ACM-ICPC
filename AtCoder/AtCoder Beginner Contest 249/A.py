(a, b, c, d, e, f, x) = map(int, raw_input().split())

ta = x / (a + c)
ra = min(a, x % (a + c))
tot_a = a * b * ta + ra * b
# print ta, a * b, ra, a

tb = x / (d + f)
rb = min(d, x % (d + f))
tot_b = d * e * tb + rb * e
# print tot_a, tot_b

if tot_a > tot_b:
    print 'Takahashi'
elif tot_a < tot_b:
    print 'Aoki'
else:
    print 'Draw'

'''
^^^^TEST^^^^
4 3 3 6 2 5 10
------
Takahashi
$$$TEST$$$




^^^^TEST^^^^
3 1 4 1 5 9 2
------
Aoki
$$$TEST$$$

^^^^TEST^^^^
1 1 1 1 1 1 1
------
Draw
$$$TEST$$$

'''
