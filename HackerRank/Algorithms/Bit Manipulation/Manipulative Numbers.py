n = int(raw_input())
ns = map(int, raw_input().split())

for i in xrange(32, -1, -1):
    d = {}
    for item in map(lambda x: x >> i, ns):
        d[item] = d.get(item, 0) + 1
    
    flag = True
    for key, value in d.items():
        if value > n / 2:
            flag = False
            break
    if flag:
        print i
        break
else:
    print -1
