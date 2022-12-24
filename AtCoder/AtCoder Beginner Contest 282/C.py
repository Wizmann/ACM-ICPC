n = int(raw_input())
s = list(raw_input())

status = 0

for i, c in enumerate(s):
    if c == "\"":
        status ^= 1
        continue
    if c == ',' and status == 0:
        s[i] = '.'
print ''.join(s)

'''
^^^^^^^^^^^^^^TEST^^^^^
8
"a,b"c,d
--------------
"a,b"c.d
$$$TEST$$$


^^^^TEST^^^
5
,,,,,
-----------------
.....
$$$$TEST$$$$

^^^^TEST^^^
20
a,"t,"c,"o,"d,"e,"r,
----------
a."t,"c."o,"d."e,"r.
$$$$TEST$$$$

'''

