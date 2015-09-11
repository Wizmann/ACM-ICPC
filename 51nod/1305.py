n = int(raw_input())
ns = map(int, [raw_input() for i in xrange(n)])

'''
s = 0
for i in xrange(n):
    for j in xrange(i + 1, n):
        s += (ns[i] + ns[j]) / ns[i] / ns[j]
print s
'''

ones, twos = 0, 0
ans = 0

for i, num in enumerate(ns):
    ans += ones
    if num == 1:
        ans += i
    if num == 2:
        ans += twos
    ones += num == 1
    twos += num == 2
print ans
