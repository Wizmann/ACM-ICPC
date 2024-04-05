g = [ "TLWWL", "XTLWL", "XXTLW", "XXXTW", "XXXXT" ]

n, na, nb = map(int, raw_input().split())
pa = map(int, raw_input().split())
pb = map(int, raw_input().split())
sa, sb = 0, 0

for i in xrange(n):
    a, b = pa[i % len(pa)], pb[i % len(pb)]
    if g[a][b] == 'W' or g[b][a] == 'L':
        sa += 1
    elif g[a][b] == 'L' or g[b][a] == 'W':
        sb += 1
print sa, sb


