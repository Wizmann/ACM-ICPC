import io
import sys
import atexit
from collections import Counter

buff = io.BytesIO()
sys.stdout = buff

@atexit.register
def write():
    sys.__stdout__.write(buff.getvalue())

raw_input = sys.stdin.readline

def calc(a, b):
    return 1.0 * a / b + 1.0 * b / a

if __name__ == '__main__':
    T = int(raw_input())
    for case_ in xrange(T):
        n = int(raw_input())
        c = Counter(map(int, raw_input().split()))
        ns = []

        mini = 10 ** 10
        ans = []

        for key, value in c.items():
            if value >= 4:
                mini = 2
                ans = [key] * 4
            if value >= 2:
                ns += [key]

        ns.sort()
        m = len(ns)

        for i in xrange(m - 1):
            u = calc(ns[i], ns[i + 1])
            v = calc(ns[i], ns[-1])

            if u < mini:
                mini = u
                ans = [ns[i], ns[i], ns[i + 1], ns[i + 1]]

            if v < mini:
                mini = v
                ans = [ns[i], ns[i], ns[-1], ns[-1]]
        print ' '.join(map(str, ans))

