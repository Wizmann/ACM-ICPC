from collections import defaultdict

n = int(raw_input())

d = defaultdict(int)

for i in xrange(n):
    name = raw_input()
    if name not in d:
        d[name] += 1
        print name
    else:
        print "%s(%d)" % (name, d[name])
        d[name] += 1

'''
^^^^^TEST^^^^
5
newfile
newfile
newfolder
newfile
newfolder
---------
newfile
newfile(1)
newfolder
newfile(2)
newfolder(1)
$$$TEST$$$$


^^^^TEST^^^^
11
a
a
a
a
a
a
a
a
a
a
a
------------
a
a(1)
a(2)
a(3)
a(4)
a(5)
a(6)
a(7)
a(8)
a(9)
a(10)
$$$$TEST$$$$

'''

