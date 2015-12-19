def find_mini(s, p):
    mini = 0x3f3f3f3f
    idx = p + 1
    for i in xrange(len(s) - 1, p, -1):
        if s[i] > s[p] and s[i] < mini:
            mini = s[i]
            idx = i
    return idx

s = sorted(map(int, list(raw_input())))
n = len(s)

while True:
    print ''.join(map(str, s))
    
    for i in xrange(n - 2, -1, -1):
        if s[i] < s[i + 1]:
            idx = find_mini(s, i)
            s[i], s[idx] = s[idx], s[i]
            s[i + 1:] = s[i + 1:][::-1]
            break
    else:
        break
