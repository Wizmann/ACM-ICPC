s = raw_input()

st = []
box = set()
result = True
for c in s:
    if c == '(':
        st.append(c)
    elif c == ')':
        while st and st[-1] != '(':
            box.remove(st.pop())
        if st:
            st.pop()
        else:
            # print 'f1'
            result = False
            break
    else:
        if c in box:
            # print 'f2'
            result = False
            break
        box.add(c)
        st.append(c)

if not result:
    print 'No'
else:
    print 'Yes'

'''

^^^TEST^^^^
((a)ba)
------------
Yes
$$$TEST$$$

^^^TEST^^^^
(a(ba))
------------
No
$$$TEST$$$

^^^TEST^^^^
(((())))
------------
Yes
$$$TEST$$$

^^^TEST^^^^
abca
------------
No
$$$TEST$$$

^^^TEST^^^^
abcd
------------
Yes
$$$TEST$$$

'''
