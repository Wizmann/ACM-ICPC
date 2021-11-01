(n, m) = map(int, raw_input().split())

mat = []

for i in xrange(n):
    mat.append(map(int, raw_input().split()))

flag = True
for i in xrange(n):
    for j in xrange(m):
        a = mat[i][j]
        if j + 1 < m:
            b = mat[i][j + 1]
            if b - a != 1:
                flag = False
            if a % 7 == 0:
                flag = False
        if i + 1 < n:
            c = mat[i + 1][j]
            if c - a != 7:
                flag = False
    if not flag:
        break

if flag:
    print 'Yes'
else:
    print 'No'
    
'''

^^^TEST^^^
2 3
1 2 3
8 9 10
---------
Yes
$$$TEST$$$


^^^TEST^^^
2 1
1
2
---------
No
$$$TEST$$$

^^^TEST^^^
2 2
1 2
8 9
---------
Yes
$$$TEST$$$

^^^TEST^^^
2 2
7 8
14 15
---------
No
$$$TEST$$$

^^^TEST^^^
10 4
1346 1347 1348 1349
1353 1354 1355 1356
1360 1361 1362 1363
1367 1368 1369 1370
1374 1375 1376 1377
1381 1382 1383 1384
1388 1389 1390 1391
1395 1396 1397 1398
1402 1403 1404 1405
1409 1410 1411 1412
---------
Yes
$$$TEST$$$


'''
