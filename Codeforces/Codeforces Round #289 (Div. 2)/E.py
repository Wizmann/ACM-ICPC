VOVELS = set('AEIOUY')

if __name__ == '__main__':
    s = raw_input()
    l = len(s)

    As = [0 for i in xrange(l + 1)]
    Bs = [0 for i in xrange(l + 1)]
    Cs = [0 for i in xrange(l + 1)]
    ans = 0

    for i, c in enumerate(s):
        if c not in VOVELS:
            continue

        (left, right) = i, l - i - 1

        As[l] += 1
        As[max(left, right)] -= 1

        Bs[max(left, right)] += min(left, right) + 1
        Bs[min(left, right)] -= min(left, right) + 1

        Cs[min(left,right)] += 1

        ans += 1

    for i in xrange(l, 1, -1):
        if i + 1 <= l:
            As[i] += As[i + 1]
        ans += 1.0 * As[i] * (l - i + 1) / i

    for i in xrange(l, 1, -1):
        if i + 1 <= l:
            Bs[i] += Bs[i + 1]
        ans += 1.0 * Bs[i] / i

    for i in xrange(l, 1, -1):
        if i + 1 <= l:
            Cs[i] += Cs[i + 1]
        ans += 1.0 * Cs[i] * i / i

    print ans
