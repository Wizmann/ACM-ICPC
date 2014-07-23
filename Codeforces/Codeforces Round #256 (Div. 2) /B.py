def cnt(s):
    l = [0 for i in xrange(26)]
    for c in s:
        l[ord(c) - ord('a')] += 1
    return l

def do_equal(a, b):
    for i in xrange(26):
        if a[i] != b[i]:
            return False
    return True

def do_contain(a, b):
    for i in xrange(26):
        if a[i] < b[i]:
            return False
    return True

def do_in(a, b):
    pa, pb = 0, 0
    lena, lenb = len(a), len(b)
    while pa < lena and pb < lenb:
        if b[pb] != a[pa]:
            pa += 1
        else:
            pa += 1
            pb += 1
    return pb == lenb

a = raw_input()
b = raw_input()

if do_in(a, b):
    print 'automaton'
else:
    al = cnt(a)
    bl = cnt(b)

    if do_equal(bl, al):
        print 'array'
    elif do_contain(al, bl):
        print 'both'
    else:
        print 'need tree'
