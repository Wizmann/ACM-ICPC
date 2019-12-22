n = int(raw_input())
ns = map(int, raw_input().split())
 
b, w = 0, 0
for i, line in enumerate(ns):
    if i % 2 == 0:
        b += (line + 1) / 2
        w += line / 2
    else:
        w += (line + 1) / 2
        b += line / 2
#print b, w
print min(b, w)
