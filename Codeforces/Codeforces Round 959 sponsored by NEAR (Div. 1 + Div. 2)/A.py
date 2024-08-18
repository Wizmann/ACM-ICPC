T = int(raw_input())

for case_ in xrange(T):
    n, m = map(int, raw_input().split())
    mat = []
    for i in xrange(n):
        mat += map(int, raw_input().split())

    if n * m == 1:
        print -1
    else:
        mat = map(lambda x: x - 1, mat)
        mat2 = map(lambda x: (x + 1) % (n * m), mat)
        for i in xrange(n):
            for j in xrange(m):
                assert mat2[i * m + j] != mat[i * m + j]
                print mat2[i * m + j] + 1,
            print ''

'''
^^^^^TEST^^^^
5
1 1
1
2 1
2
1
1 5
2 4 5 3 1
2 4
1 2 3 4
5 6 7 8
3 3
4 2 1
9 8 3
6 7 5
---------------
<spj>
$$$TEST$$$
'''





