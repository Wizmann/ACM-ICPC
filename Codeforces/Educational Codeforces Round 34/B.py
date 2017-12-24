if __name__ == '__main__':
    (h1, a1, c1) = map(int, raw_input().split())
    (h2, a2) = map(int, raw_input().split())

    res = []

    while h2 > 0:
        if a1 >= h2:
            res.append('STRIKE')
            h2 -= a1
        elif h1 > a2:
            res.append('STRIKE')
            h2 -= a1
            h1 -= a2
        else:
            res.append('HEAL')
            h1 += c1
            h1 -= a2

    print len(res)
    print '\n'.join(res)

