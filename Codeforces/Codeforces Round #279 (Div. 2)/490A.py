n = int(raw_input())
students = map(int, raw_input().split())

pros    = [i + 1 for i in xrange(n) if students[i] == 1]
maths   = [i + 1 for i in xrange(n) if students[i] == 2]
sports  = [i + 1 for i in xrange(n) if students[i] == 3]

ans = []

while pros and maths and sports:
    ans.append((pros[0], maths[0], sports[0]))
    del pros[0]
    del maths[0]
    del sports[0]
    
print len(ans)

for gruop in ans:
    print ' '.join(map(str, gruop))
