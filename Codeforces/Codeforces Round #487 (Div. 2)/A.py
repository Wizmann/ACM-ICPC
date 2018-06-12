def solve(s):
    n = len(s)
    last = ['' for i in xrange(n)]

    for i in xrange(n):
        if i - 1 >= 0:
            last[i - 1] += s[i]
        last[i] += s[i]
        if i + 1 < n:
            last[i + 1] += s[i]

    for i in xrange(n):
        if set(last[i]) == set('ABC'):
            return True
    return False

assert solve('.BAC.') == True
assert solve('AA..CB') == False

if __name__ == '__main__':
    s = raw_input()
    print 'Yes' if solve(s) else 'No'
