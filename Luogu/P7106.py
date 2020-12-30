def solve(color):
    r = int(color[1:3], 16)
    g = int(color[3:5], 16)
    b = int(color[5:7], 16)
    r = 255 - r
    g = 255 - g
    b = 255 - b
    return '#%02X%02X%02X' % (r, g, b)

assert solve('#FFFFFF') == '#000000'
assert solve('#EBA932') == '#1456CD'

print solve(raw_input())

'''
^^^TEST^^^
#EBA932
---
#1456CD
$$$TEST$$$
'''
