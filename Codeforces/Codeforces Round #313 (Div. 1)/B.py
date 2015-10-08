def mysort(s):
    if len(s) % 2 != 0:
        return s
    l = len(s)
    s1, s2 = s[:l / 2], s[l / 2:]
    s1 = mysort(s1)
    s2 = mysort(s2)
    return min(s1, s2) + max(s1, s2)

a = raw_input()
b = raw_input()

print 'YES' if mysort(a) == mysort(b) else 'NO'
