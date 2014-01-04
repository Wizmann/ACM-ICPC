def judge(nr, pp):
    for i, s in enumerate(pp):
        if i == nr:
            continue

        t = pp[nr] | s

        if t == pp[nr]:
            return False
    return True

n = int(raw_input())

pp = []
for i in xrange(n):
    l = map(int, raw_input().split())[1:]
    pp.append(set(l))

for i in xrange(n):
    if judge(i, pp):
        print 'YES'
    else:
        print 'NO'
