from math import sqrt

primes = set([2, 3, 5, 7])

def check_left(v):
    if v in primes:
        next = str(v)[:-1]
        if not next:
            return True
        return check_left(int(next))

    else:
        return False

def check_right(v):
    if v in primes:
        next = str(v)[1:]
        if not next:
            return True
        return check_right(int(next))
    else:
        return False

def is_prime(v):
    for i in xrange(2, int(sqrt(v) + 1)):
        if v % i == 0:
            return False
    return True

def main():
    v = 10
    cnt = 0
    res= []
    while True:
        if is_prime(v):
            primes.add(v)

            if check_left(v) and check_right(v):
                res.append(v)
                cnt += 1
                print '>>', v

                if cnt == 11:
                    break
        v += 1
    print sum(res)


# [23, 37, 53, 73, 313, 317, 373, 797, 3137, 3797, 739397]

main()


