pos = raw_input()
x, y = pos[0], pos[1]

x = ord(x) - ord('a') + 1
y = int(y)

ans = 0
for i in xrange(-1, 2, 1):
    for j in xrange(-1, 2, 1):
        ny, nx = y + i, x + j
        if 1 <= nx <= 8 and 1 <= ny <= 8:
            ans += 1
print ans - 1
