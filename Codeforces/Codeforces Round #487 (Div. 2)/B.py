def do_fill(s):
    return ''.join(s).replace('.', '1')

def solve(n, k, s):
    s = list(s)
    for i in xrange(n):
        if i + k < n:
            a, b = s[i], s[(i + k) % n]
            if '.' not in [a, b] and a != b:
                return do_fill(s)
            elif a == '.' and b == '.':
                s[i], s[i + k] = '1', '0'
                return do_fill(s)
            elif a == '.':
                s[i] = str(int(s[(i + k) % n]) ^ 1)
                return do_fill(s)
            elif b == '.':
                s[(i + k) % n] = str(int(s[i]) ^ 1)
                return do_fill(s)
            
    return 'No'

assert solve(10, 7, '1.0.1.0.1.')
assert solve(10, 6, '1.0.1.1000')
assert solve(10, 9, '1........1') == 'No'

if __name__ == '__main__':
    (n, k) = map(int, raw_input().split())
    s = raw_input()

    print solve(n, k, s)
