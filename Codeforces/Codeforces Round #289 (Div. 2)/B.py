(n, k) = map(int, raw_input().split())
ps = map(int, raw_input().split())

(mini, maxi) = min(ps), max(ps)

if maxi - mini > k:
    print 'NO'
    exit(0)

print 'YES'
for p in ps:
    r = [1 for i in xrange(mini)] + [i + 1 for i in xrange(p - mini)]
    print ' '.join(map(str, r))
