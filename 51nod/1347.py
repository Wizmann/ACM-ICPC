import sys

def solve(line):
    n = len(line)
    if n % 2:
        return False
    p, q = 0, n / 2
    
    cnt = 0
    while p < n and cnt < n / 2:
        if line[p % n] == line[q % n]:
            cnt += 1
        else:
            cnt = 0
        p += 1
        q += 1
    return cnt == n / 2

for line in sys.stdin:
    if solve(line.strip()):
        print 'YES'
    else:
        print 'NO'
