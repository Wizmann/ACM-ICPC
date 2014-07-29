(n, m) = map(int, raw_input().split())

step = 0
inc = n * m

while inc:
    inc -= (n + m) - 1
    step += 1
    n -= 1
    m -= 1

if step % 2:
    print 'Akshat'
else:
    print 'Malvika'
