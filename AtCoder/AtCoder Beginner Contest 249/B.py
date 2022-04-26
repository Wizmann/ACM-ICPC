import string
s = raw_input()

flag1, flag2, flag3 = False, False, False

for c in string.ascii_lowercase:
    if c in s:
        flag1 = True
        break

for c in string.ascii_uppercase:
    if c in s:
        flag2 = True
        break

if len(s) == len(set(s)):
    flag3 = True

if flag1 and flag2 and flag3:
    print 'Yes'
else:
    print 'No'


'''
^^^^^TEST^^^
Perfect
-----
No
$$$TEST$$$

^^^^^TEST^^^
AtCoder
-----
Yes
$$$TEST$$$
'''

