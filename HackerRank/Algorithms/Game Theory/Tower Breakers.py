def solve(n, m):
    if n % 2 == 0:
        return 2
    elif m == 1:
        return 2
    else:
        return 1
    
if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        (a, b) = map(int, raw_input().split())
        print solve(a, b)
