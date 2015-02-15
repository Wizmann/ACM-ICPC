import sys

def do_fill(num, ptr, delta):
    for i in xrange(ptr):
        num[i] = min(9, delta)
        delta -= num[i]
    return delta == 0

def solve(num, pre):
    l = len(pre)
    i = 0

    while True:
        t = pre + [0 for j in xrange(i - l + 1)]
        while t[i] + 1 < 10:
            t[i] += 1
            for j in xrange(i):
                t[j] = 0
            delta = num - sum(t)
            if delta < 0:
                break
            if do_fill(t, i, delta):
                return t
        i += 1

if __name__ == '__main__':
    ns = map(int, sys.stdin)[1:]
    ans = [[0]]

    for num in ns:
        ans.append(solve(num, ans[-1]))

    for item in ans[1:]:
        print ''.join(map(str, item[::-1]))

