from collections import defaultdict

n = int(raw_input())

d = defaultdict(int)
st = set()

for i in xrange(n):
    s = raw_input()
    if s in st:
        continue
    st.add(s)
    if s.startswith('!'):
        s = s[1:]
    d[s] += 1

for (key, value) in d.items():
    if value > 1:
        print key
        break
else:
    print 'satisfiable'


'''
^^^TEST^^^
6
a
!a
b
!c
d
!d
----
a
$$$TEST$$$

^^^TEST^^^
10
red
red
red
!orange
yellow
!blue
cyan
!green
brown
!gray
-----
satisfiable
$$$TEST$$$
'''
