def solve(s):
    p = s.count('#')
    s = list(s)
    n = len(s)

    ss = s[:]

    q = 0
    l, r = 0, 0
    flag = False
    for i in xrange(n):
        if s[i] == '#':
            q += 1
        if s[i] == '#' and p != q:
            s[i] = ')'

        #print s
        if s[i] == '(':
            if flag:
                r += 1
            else:
                l += 1
        elif s[i] == ')':
            if flag:
                r -= 1
            else:
                l -= 1
        if l < 0:
            return [-1]
    #print s, l, r
    if r > 0:
        return [-1]
    elif abs(r) + 1 > abs(l):
        return [-1]
    else:
        res = [1] * (p - 1)
        res += [abs(l) - abs(r)]
        if do_test(ss, res):
            return res
        else:
            return [-1]

def do_test(s, p):
    ss = ''
    idx = 0
    for i, c in enumerate(s):
        if c in '()':
            ss += c
        else:
            ss += ')' * p[idx]
            idx += 1
    score = 0
    for c in ss:
        if c == '(':
            score += 1
        else:
            score -= 1
        if score < 0:
            return False
    return score == 0

def test(s):
    p = solve(s)
    if p == [-1]:
        return True
    ss = ''
    idx = 0
    for i, c in enumerate(s):
        if c in '()':
            ss += c
        else:
            ss += ')' * p[idx]
            idx += 1
    score = 0
    for c in ss:
        if c == '(':
            score += 1
        else:
            score -= 1
        if score < 0:
            return False
    return score == 0


assert solve('(#') == [1]
assert solve('###') == [-1]
assert solve('#)#') == [-1]
assert solve('(##') == [-1]
assert solve('((#)(') == [-1]


assert test('(((#)((#)')
assert test('()((#((#(#()')
assert test('(#)')

print '\n'.join(map(str, solve(raw_input())))
