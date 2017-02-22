def minion_game(s):
    if not s:
        print 'Draw'
        return
    
    vowel = list('aeiou')
    n = len(s)
    s = s.lower()
    l, r = 0, 0
    for i in xrange(n):
        c = s[i]
        if c not in vowel:
            l += n - i
        else:
            r += n - i
    if l == r:
        print 'Draw'
    elif l > r:
        print 'Stuart', l
    else:
        print 'Kevin', r

if __name__ == '__main__':
    s = raw_input()
    minion_game(s)
