n = int(raw_input())
As, Bs = [], []
for i in xrange(n):
    a, b = map(int, raw_input().split())
    As.append(a)
    Bs.append(b)
    
p = 0
cnt = 0
q = 0
cur = 0
while True:
    cur += As[q]
    cnt += 1
    #print p, q, cur, cnt
    if cnt == n:
        print p
        break
    else:
        cur -= Bs[q]
        if cur < 0:
            p = q = max((p + 1) % n, q)
            cnt = cur = 0
            continue
    q = (q + 1) % n
            
