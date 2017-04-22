INF = 10 ** 10

if __name__ == '__main__':
    n = int(raw_input())
    ns = map(int, raw_input().split())

    pos = sorted(filter(lambda x: x >= 0, ns))
    neg = sorted(filter(lambda x: x < 0, ns))

    if sum(pos) % 2 == 1:
        print sum(pos)
    else:
        a, b = -INF, -INF
        for item in neg[::-1]:
            if item % 2 == 1:
                a = sum(pos) + item
                break

        for item in pos:
            if item % 2 == 1:
                b = sum(pos) - item
                break
        print max(a, b)
