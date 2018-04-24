def solve(s):
    a, b, c = s.count('a'), s.count('b'), s.count('c')
    if s != 'a' * a + 'b' * b + 'c' * c:
        return False
    if a == 0 or b == 0:
        return False
    return c in [a, b]

assert solve('aaabccc')
assert solve('bbacc') == False
assert solve('aabc')
assert solve('aabcc')
assert solve('aacc') == False
assert solve('bbcc') == False

if __name__ == '__main__':
    s = raw_input()
    print 'YES' if solve(s) else 'NO'
