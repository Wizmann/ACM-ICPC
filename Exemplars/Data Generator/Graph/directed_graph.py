import sys
import random

if __name__ == '__main__':
    if len(sys.argv) == 2:
        n = int(sys.argv[1])
        m = random.randint(n - 1, n * n)
    elif len(sys.argv) == 3:
        n = int(sys.argv[1])
        m = int(sys.argv[2])
    else:
        n = random.randint(1, 100)
        m = random.randint(n - 1, n * n)

    print n, m

    for i in xrange(m):
        a, b, c = random.randint(0, n - 1), random.randint(0, n - 1), random.randint(1, 1000)
        print a, b, c
