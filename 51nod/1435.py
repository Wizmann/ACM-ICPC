import sys

sys.stdin = open('input.txt')

n = int(raw_input())
ns = map(int, list(raw_input()))
factors = [0 for i in xrange(10)]

for num in ns:
    for i in xrange(2, num + 1):
        for j in xrange(2, 10):
            while i % j == 0:
                factors[j] += 1
                i /= j

res = ''
for num in [7, 5, 3, 2]:
    u = factors[num]
    if not u:
        continue
    res += str(num) * u
    for i in xrange(2, num + 1):
        for j in xrange(2, 10):
            while i % j == 0:
                i /= j
                factors[j] -= u

print ''.join(sorted(list(res), reverse=True))
