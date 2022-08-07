n = int(raw_input())

matrix = []
for i in xrange(n):
    matrix.append(raw_input())

d = {'W': 1, 'L': -1, 'D': 0}

flag = True
for i in xrange(n):
    for j in xrange(i + 1, n):
        a = d[matrix[i][j]]
        b = d[matrix[j][i]]

        if a != -b:
            flag = False
            break

if flag:
    print 'correct'
else:
    print 'incorrect'


'''
^^^^TEST^^^
4
-WWW
L-DD
LD-W
LDW-
-----------
incorrect
$$$TEST$$$$


^^^^TEST^^^
2
-D
D-
------
correct
$$$$TEST$$$
'''

