# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

MAXI = 10 ** 7

def solution(A):
    l = []
    for i, item in enumerate(A):
        l.append((i - item, -1, i))
        l.append((i + item, +1, i))
        
    l.sort()
    s = set()
    
    ans = 0
    for item in l:
        (p, cmd, idx) = item
        if cmd == -1:
            ans += len(s)
            if ans > MAXI:
                ans = -1
                break
            s.add(idx)
        else:
            s.remove(idx)

    return ans
