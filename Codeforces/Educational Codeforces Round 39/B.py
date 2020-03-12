def solve(a, b):
    while a and b:
        if a >= 2 * b:
            a %= 2 * b
        elif b >= 2 * a:
            b %= 2 * a
        else:
            break
    return (a, b)

assert solve(12, 5) == (0, 1)
assert solve(31, 12) == (7, 12)

if __name__ == '__main__':
    (a, b) = solve(*map(int, raw_input().split()))
    print a, b
