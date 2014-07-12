(n, m) = map(int, raw_input().split())
mp = [list(raw_input()) for i in xrange(n)]

for i in xrange(n):
    c = i & 1
    for j in xrange(m):
        if mp[i][j] == '.':
            mp[i][j] = 'B' if c else 'W'
        c ^= 1

for line in mp:
    print ''.join(line)
