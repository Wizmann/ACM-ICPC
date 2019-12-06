import sys
 
def test(s):
    n = len(s)
    for i in xrange(1, n):
        if s[i - 1] == s[i]:
            return False
    return True
 
def solve(s):
    s = list(s)
    n = len(s)
    alpha = 'abc'
 
    for i in xrange(n):
        if s[i] == '?':
            l = '?' if i - 1 < 0 else s[i - 1]
            r = '?' if i + 1 >= n else s[i + 1]
            a = set('abc')
            if l in a:
                a ^= set(l)
            if r in a:
                a ^= set(r)
            a = list(a)[0]
            s[i] = a
 
    if test(s):
        return ''.join(s)
    else:
        return '-1'
 
 
 
 
assert test(solve('???'))
assert test(solve('????'))
assert test(solve('abc'))
assert test(solve('?bc'))
assert test(solve('?b?'))
assert test(solve('?b?b?'))
assert test(solve('a???cb'))
 
assert solve('???') != -1
assert solve('????') != '-1'
assert solve('abc')!= '-1'
assert solve('?bc')!= '-1'
assert solve('?b?')!= '-1'
assert solve('?b?b?')!= '-1'
assert solve('a???cb')!= '-1'
assert solve('a???cb') != '-1'
 
assert solve('a??bbc') == '-1'
assert test(solve('a?b?c'))
 
n = int(raw_input())
for line in sys.stdin:
    line = line.strip()
    print solve(line)
