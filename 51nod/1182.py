d = {}
for item in raw_input().lower():
    d[item] = d.get(item, 0) + 1
    
res = 0
l = sorted(d.values(), reverse=True)
for i, num in enumerate(l):
    res += (26 - i) * num
print res
