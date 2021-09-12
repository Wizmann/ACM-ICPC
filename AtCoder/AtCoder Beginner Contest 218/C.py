INF = 10 ** 10

def parse(n):
    points = []
    for i in xrange(n):
        line = raw_input()
        for j, c in enumerate(line):
            if c == '#':
                points.append((i, j))
    return points

def normalize(S):
    minx, miny = INF, INF
    for (y, x) in S:
        minx = min(x, minx)
        miny = min(y, miny)
    S_ = []
    for (y, x) in S:
        S_.append((y - miny, x - minx))
    S_.sort()
    return S_

def translate(n, S):
    S_ = []
    for (y, x) in S:
        S_.append((x, n - y - 1))
    S_ = normalize(S_)
    # print S, S_
    return S_

n = int(raw_input())

S = parse(n)
T = parse(n)

S = normalize(S)
T = normalize(T)

for i in xrange(4):
    # print S, T
    if S == T:
        print 'Yes'
        break
    S = translate(n, S)
else:
    print 'No'
    
'''
^^^TEST^^^
5
.....
..#..
.###.
.....
.....
.....
.....
....#
...##
....#
------
Yes
$$$TEST$$$

^^^TEST^^^
5
#####
##..#
#..##
#####
.....
#####
#..##
##..#
#####
.....
--------
No
$$$TEST$$$

^^^TEST^^^
4
#...
..#.
..#.
....
#...
#...
..#.
....
--------
Yes
$$$TEST$$$

'''
