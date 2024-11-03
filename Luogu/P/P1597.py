d = {
    'a' : 0,
    'b' : 0,
    'c' : 0
}

for p in input().split(';'):
    if not p.strip():
        continue
    k, v = list(map(lambda x: x.strip(), p.split(':=')))
    if v.isdigit():
        d[k] = v
    else:
        d[k] = d[v]

print(d['a'], d['b'], d['c'])
