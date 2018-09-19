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

    print n
    vertices = range(n)

    root = random.choice(vertices)
    leaves = set([root])
    remains = set(vertices) ^ set([root])

    while remains:
        a = random.choice(list(leaves))
        b = random.choice(list(remains))

        assert a != b

        print a, b, random.randint(1, 1000)
        remains.remove(b)
        m -= 1

    while m:
        a, b = -1, -1
        while a == b:
            a = random.choice(vertices)
            b = random.choice(vertices)
        print a, b, random.randint(1, 1000)
        m -= 1



