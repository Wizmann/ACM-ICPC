n = int(raw_input())

ops = []

for i in xrange(n):
    a, b, c = raw_input().split()
    if b == '=':
        b = '=='
    ops.append("%f" + b + c)
        
ans = 0

for i in xrange(-10, 10240, 5):
    cnt = 0
    i = float(i) / 10
    for op in ops:
        if eval(op % i) == True:
            cnt += 1
    ans = max(ans, cnt)
    
print ans
