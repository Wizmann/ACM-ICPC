def solve(n, x, ns):
    flag = False
    rem = x
    for i in xrange(n):
        if ns[i] == 0:
            if flag:
                rem -= 1
        elif ns[i] == 1:
            if not flag:
                flag = True
                rem -= 1
            else:
                rem -= 1

            if rem < 0:
                return False
    return True

T = int(raw_input())

for case_ in xrange(T):
    n, x = map(int, raw_input().split())
    ns = map(int, raw_input().split())

    if solve(n, x, ns):
        print 'YES'
    else:
        print 'NO'


'''
^^^^TEST^^^^^
7
4 2
0 1 1 0
6 3
1 0 1 1 0 0
8 8
1 1 1 0 0 1 1 1
1 2
1
5 1
1 0 1 0 1
7 4
0 0 0 1 1 0 1
10 3
0 1 0 0 1 0 0 1 0 0
-----------
YES
NO
YES
YES
NO
YES
NO
$$$$TEST$$$$
'''


