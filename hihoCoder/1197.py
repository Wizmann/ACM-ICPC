import sys

res = []

def solve(seg):
    if not seg.strip():
        return
    seg = seg.lower()
    seg = filter(lambda x: x, seg.split(' '))
    seg = ' '.join(seg)
    seg = map(lambda x: x.strip(), seg.split(','))
    seg = ', '.join(seg)
    seg = seg[0].upper() + seg[1:] + '.'
    return seg
    
for line in sys.stdin:
    segs = line.split('.')
    tmp = []
    for seg in segs:
        s = solve(seg)
        if s:
            tmp.append(s)
    res.append(' '.join(tmp))

print '\n'.join(res)
