import math

eps = 1e-6

S = int(raw_input())

def tri(r):
    a = math.pi * r
    b = math.pi * r * r
    
    h = math.sqrt(S / a * (S - 2 * b) / a)
    
    return b * h / 3.0

l, r = 0, math.sqrt(S / 2 / math.pi)

while abs(r - l) > eps:
    lt = (l + r) / 2
    rt = (lt + r) / 2
    ltVal, rtVal = tri(lt), tri(rt)
    if ltVal >= rtVal:
        r = rt
    else:
        l = lt
    
print tri(l)

