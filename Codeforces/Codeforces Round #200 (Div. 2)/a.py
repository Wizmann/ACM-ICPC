n = int(raw_input())

magnets = []

for i in xrange(n):
    x = raw_input()
    if x == '10':
        magnets.append(0)
    else:
        magnets.append(1)

magnets.append(-1)
l = len(magnets)
group = 0
pre = -1

for i in xrange(l):
    if magnets[i] != pre:
        group += 1
        pre = magnets[i]

print group - 1
