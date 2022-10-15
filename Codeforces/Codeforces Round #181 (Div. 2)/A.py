n = int(raw_input())

ns = map(int, raw_input().split())

neg = filter(lambda x: x < 0, ns)
pos = filter(lambda x: x > 0, ns)
zero = filter(lambda x: x == 0, ns)

s1, s2, s3 = [], [], []

assert neg
s1 = [neg.pop()]

if pos:
    s2 = [pos.pop()]
else:
    assert len(neg) >= 2
    s2 = [neg.pop(), neg.pop()]

s3 = zero + pos + neg

print len(s1), ' '.join(map(str, s1))
print len(s2), ' '.join(map(str, s2))
print len(s3), ' '.join(map(str, s3))

'''

^^^^^^TEST^^^^
3
-1 2 0
-----------
1 -1
1 2
1 0
$$$TEST$$$$

^^^^^^TEST^^^^
4
-1 -2 -3 0
-----------
1 -1
2 -3 -2
1 0
$$$TEST$$$$

^^^^^^TEST^^^^
3
-1 2 0
-----------
1 -1
1 2
1 0
$$$TEST$$$$

'''



