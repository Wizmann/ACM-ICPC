import sys
sys.stdin = open('input.txt')

if __name__ == '__main__':
    (n, m, k) = map(int, raw_input().split())
    ns = map(int, raw_input().split())

    maxi = max(ns)

    prefix = [0 for i in xrange(maxi + 1)]

    for num in ns:
        prefix[num] = 1

    for i in xrange(1, maxi + 1):
        prefix[i] += prefix[i - 1]

    res = 0
    for i in xrange(k, maxi + 1):
        u = prefix[i] - prefix[i - k]
        if u + m >= k:
            res = max(res, i)
    print res
