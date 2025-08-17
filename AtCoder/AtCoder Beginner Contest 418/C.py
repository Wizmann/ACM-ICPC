#python3
xrange = range
n = int(input())

rs = []
cs = []

for i in xrange(n):
    r, c = list(map(int, input().split()))
    rs.append(r)
    cs.append(c)

print(max(
    (max(rs) - min(rs) + 1) // 2,
    (max(cs) - min(cs) + 1) // 2
))

'''
^^^^TEST^^^^
3
2 3
5 1
8 1
---------
3
$$$$TEST$$$$

^^^^TEST^^^^
5
6 7
6 7
6 7
6 7
6 7
---------
0
$$$$TEST$$$$

^^^^TEST^^^^
6
91 999999986
53 999999997
32 999999932
14 999999909
49 999999985
28 999999926
---------
44
$$$$TEST$$$$

'''
