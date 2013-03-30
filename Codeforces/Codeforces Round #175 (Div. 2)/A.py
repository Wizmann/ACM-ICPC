#Mar 23, 2013 8:44:00 AM    Wizmann  A - Slightly Decreasing Permutations    Python Accepted    78 ms   6660 KB
a, b = map(int, raw_input().split())
if b == 0:
    ans = [i + 1 for i in xrange(a)]
else:
    st = [i + 1 for i in xrange(a - b - 1)]
    end = [i + 1 for i in xrange(a - b - 1, a)][::-1]
    ans = st + end
print ' '.join(map(str, ans))
