from collections import Counter

s = raw_input()
n = len(s)
c = Counter(s)

maxi = max(c.values())
if maxi <= (n + 1) / 2:
    print 'Possible'
else:
    print 'Impossible'
