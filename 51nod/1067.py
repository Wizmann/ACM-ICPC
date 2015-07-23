wl = [0, 1, 0, 1]
for i in xrange(10):
    ptr = 4 + i
    u = (wl[ptr - 1] ^ 1)| (wl[ptr - 3] ^ 1) | (wl[ptr - 4] ^ 1)
    wl.append(u)

n = int(raw_input())
for i in xrange(n):
    x = int(raw_input()) % 7
    print 'A' if wl[x] else 'B'
