n = int(raw_input())
fs, bs = set([]), set([])
forw = {}
for i in xrange(n):
    (before, after) = map(int, raw_input().split())
    fs.add(before)
    bs.add(after)
    forw[before] = after

x, y = list(fs - bs)[0], forw[0]

ans = []

while True:
    ans += [x, y]
    try:
        x, y = forw[x], forw[y]
    except:
        break

ans = filter(lambda x: x, ans)

print ' '.join(map(str, ans))
    
