a, b = 1, 1
d = {1: 1}
idx = 3
while True:
    c = (a + b)
    l = len(str(c))
    if l not in d:
        d[l] = idx
    idx += 1

    if l > 5000:
        break
    a, b = b, c

T = int(raw_input())
for case_ in xrange(T):
    print d[int(raw_input())]
