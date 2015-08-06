import string

ALPHA_NUM = len(string.ascii_uppercase)

d = dict(
    zip(string.ascii_uppercase, [0 for i in xrange(ALPHA_NUM)])
)

s = raw_input()
p, q = 0, 0
cnt = 0
n = len(s)
ans = 0xdeadbeef

while q < n:
    c = s[q]
    if d[c] == 0:
        cnt += 1
    d[c] += 1
    
    while cnt == ALPHA_NUM:
        ans = min(ans, q - p + 1)
        cc = s[p]
        if d[cc] == 1:
            cnt -= 1
        d[cc] -= 1
        p += 1
    q += 1
print 'No Solution' if ans == 0xdeadbeef else ans
