from collections import Counter

def calc(k, s):
    n = len(s)
    _, m = max(Counter(s).items(), key=lambda (key, value): value)

    if m == n and k == 1:
        return n - 1
    elif m + k <= n:
        return m + k
    else:
        return n

if __name__ == '__main__':
    k = int(raw_input())
    ns = [raw_input() for i in xrange(3)]

    a = map(lambda s: calc(k, s), ns)
    b = ["Kuro", "Shiro", "Katie"]

    if a.count(max(a)) != 1:
        print 'Draw'
    else:
        print max(zip(a, b))[1]