n = int(raw_input())
apples = map(int, raw_input().split())

n1 = apples.count(100)
n2 = apples.count(200)

if (n1 + 2 * n2) % 2 != 0:
    print 'NO'
else:
    v = (n1 + 2 * n2) / 2
    if v % 2 != 0 and n1 == 0:
        print 'NO'
    else:
        print 'YES'
