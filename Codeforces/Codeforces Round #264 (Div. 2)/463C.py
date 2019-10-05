n = int(raw_input())

ns = []

for i in xrange(n):
    line = map(int, raw_input().split())
    ns.append(line)

d1, d2 = {}, {}
for i in xrange(-n + 1, n):
    tot = 0
    for j in xrange(n):
        y = j
        x = i + j
        if y < 0 or x < 0 or y >= n or x >= n:
            continue
        tot += ns[y][x]
    d1[i] = tot

for i in xrange(0, n + n):
    tot = 0
    for j in xrange(n):
        y = j
        x = i - j
        if y < 0 or x < 0 or y >= n or x >= n:
            continue
        tot += ns[y][x]
    d2[i] = tot

#print d1
#print d2

maxi1, maxi2 = 0, 0
p1, p2 = (0, 0), (0, 1)
for i in xrange(-n + 1, n):
    for j in xrange(0, n + n):
        if i % 2 == 0 and j % 2 == 0:
            y = abs(i - j) / 2
            x = i + y
            if 0 <= x < n and 0 <= y < n:
                tot = d1[i] + d2[j] - ns[y][x]
                if tot > maxi1:
                    maxi1 = tot
                    p1 = (y, x)
        elif i % 2 == 1 and j % 2 == 1:
            y = abs(i - j) / 2
            x = i + y
            if 0 <= x < n and 0 <= y < n:
                tot = d1[i] + d2[j] - ns[y][x]
                if tot > maxi2:
                    maxi2 = tot
                    p2 = (y, x)
        else:
            continue
print maxi1 + maxi2
print p1[0] + 1, p1[1] + 1, p2[0] + 1, p2[1] + 1

