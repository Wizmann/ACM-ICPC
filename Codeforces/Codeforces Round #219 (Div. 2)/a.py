k = int(raw_input())

cnt = [0 for i in xrange(12)]

for i in xrange(4):
    t = map(int, raw_input().replace('.',''))
    for item in t:
        cnt[item]+= 1

res = True

for item in cnt:
    if item > k * 2:
        res = False
        break

print 'YES' if res else 'NO'

