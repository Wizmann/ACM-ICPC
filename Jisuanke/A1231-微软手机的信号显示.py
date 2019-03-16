tpl = '''\
+-----+
|Y  XX|
|YY   |
|YYY  |
|YYYY |
|YYYYY|
+-----+'''.split('\n')

d = int(raw_input())

t = d / 20
for i in xrange(1, 6):
    if t >= i:
        tpl[i] = tpl[i].replace('Y', '-')
    else:
        tpl[i] = tpl[i].replace('Y', ' ')
        
if d < 60:
    tpl[1] = tpl[1].replace('XX', ' E')
elif d < 90:
    tpl[1] = tpl[1].replace('XX', '3G')
else:
    tpl[1] = tpl[1].replace('XX', '4G')
    
print '\n'.join(tpl)
