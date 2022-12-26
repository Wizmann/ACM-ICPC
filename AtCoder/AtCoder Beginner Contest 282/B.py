(n, m) = map(int, raw_input().split())

ps = []

for i in xrange(n):
    line = raw_input().replace('o', '1').replace('x', '0')
    bits = int(line, 2)
    ps.append(bits)

cnt = 0
for i in xrange(n):
    for j in xrange(i + 1, n):
        if (ps[i] | ps[j]) == (1 << m) - 1:
            cnt += 1
print cnt

'''
^^^^TEST^^^^
5 5
ooooo
oooxx
xxooo
oxoxo
xxxxx
-----------
5
$$$$TEST$$$$

'''


