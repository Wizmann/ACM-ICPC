def is_lychrel(v, it=50):
    n = v
    u = v
    for i in xrange(it):
        u = v + int(str(v)[::-1])
        if str(u) == str(u)[::-1]:
            #print n
            return False
        v = u
    return True

def test():
    assert(not is_lychrel(47, 10))
    assert(not is_lychrel(349, 10))
    assert(not is_lychrel(10677, 60))
    assert(is_lychrel(4994, 50))

#test()
print len(filter(lambda x: x, [is_lychrel(i) for i in xrange(10000)]))
