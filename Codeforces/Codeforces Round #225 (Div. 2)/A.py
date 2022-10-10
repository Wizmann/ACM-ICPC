n = int(raw_input())

m = (n * n + 1) / 2

print m
for i in xrange(n):
    line = ['.' for j in xrange(n)]
    if i % 2 == 0:
        for j in xrange(0, n, 2):
            line[j] = 'C'
    else:
        for j in xrange(1, n, 2):
            line[j] = 'C'
    print ''.join(line)


'''
^^^^^TEST^^^^
2
------------------
2
C.
.C
$$$TEST$$$


^^^^^^^^^^TEST^^^^
3
------------------
5
C.C
.C.
C.C
$$$$$$$$TEST$$$

^^^^^^^^^^TEST^^^^
7
------------------
25
C.C.C.C
.C.C.C.
C.C.C.C
.C.C.C.
C.C.C.C
.C.C.C.
C.C.C.C
$$$$$$$$TEST$$$
'''


