def solve(n, a, b, ns):
    s = set(ns)
    
    for item in ns:
        if item in s and (b - item) in s:
            s.remove(item)
            if b - item in s:
                s.remove(b - item)
    if not s:
        return True
        
    s = set(ns)
    
    for item in ns:
        if item in s and (a - item) in s and a - item != item:
            s.remove(item)
            s.remove(a - item)

    for item in s:
        if (b - item) not in s and a - item != item:
            return False
    return True

(n, a, b) = map(int, raw_input().split())

ns = map(int, raw_input().split())

print 'YES' if solve(n, a, b, ns) else 'NO'
