from collections import defaultdict

n = int(raw_input())

d1 = defaultdict(int)
d2 = defaultdict(int)
names = []
for i in xrange(n):
    name1, name2 = raw_input().split()
    d1[name1] += 1
    d2[name2] += 1
    names.append((name1, name2))

flag = True
for (name1, name2) in names:
    if name1 == name2:
        if d1[name1] > 1 or d2[name1] > 1:
            flag = False
            break
    else:
        if ((d1[name1] <= 1 and d2[name1] == 0) or
            (d1[name2] == 0 and d2[name2] <= 1)):
            pass
        else:
            flag = False
            break
if flag:
    print 'Yes'
else:
    print 'No'

'''
^^^^TEST^^^^
3
tanaka taro
tanaka jiro
suzuki hanako
-----
Yes
$$$TEST$$$

^^^^TEST^^^^
3
aaa bbb
xxx aaa
bbb yyy
-----
No
$$$TEST$$$

^^^^TEST^^^^
2
tanaka taro
tanaka taro
-----
No
$$$TEST$$$

^^^^TEST^^^^
3
takahashi chokudai
aoki kensho
snu ke
-----
Yes
$$$TEST$$$

^^^^TEST^^^^
3
a a
b b
c a
-----
No
$$$TEST$$$

'''

