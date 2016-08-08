def is_prime(x):
    if x <= 1:
        return False
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True


def corners():
    i = 1
    while True:
        if i == 1:
            yield [1]
        else:
            x = i * 2 - 1
            res = []
            for j in xrange(4):
                res.append((x ** 2) - (x - 1) * j)
            yield res

        i += 1


d = corners()

i, a, b = 0, 0, 0

assert(len(filter(is_prime, [1, 2, 3])) == 2)

while True:
    l = d.next()
    b += len(l)
    a += len(filter(is_prime, l))

    ratio = 100.0 * a / b
    if i > 0 and ratio < 10:
        print i * 2 + 1
        break

    i += 1

