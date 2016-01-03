import sys

def rev(s):
    res = ''
    for item in s:
        if item == '+':
            res += '*'
        else:
            res += '+'
    return res

n = int(raw_input())

if n == 0:
    print '+'
    sys.exit(0)
    
res = [
    ['+'],
    ['+*', '++']
]

for i in xrange(1, n + 1):
    l = res[-1][:]
    t = []
    
    for item in l:
        t.append(item + item)
        t.append(item + rev(item))
    res.append(t)
    
print '\n'.join(res[n])

def test():
    for line in res[1:]:
        for a in line:
            for b in line:
                if a == b:
                    continue
                s = len(a)
                r = 0
                for i in xrange(s):
                    if a[i] == b[i]:
                        r += 1
                    else:
                        r -= 1
                assert(r == 0)
                
#test()
         
