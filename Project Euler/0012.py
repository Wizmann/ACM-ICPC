from math import sqrt
def gen():
    s = 0
    i = 1
    while True:
        yield s + i
        s += i
        i += 1

def split(x):
    ans = 1
    uu = int(sqrt(x)) + 1
    for i in xrange(2, uu):
        c = 0
        while x % i == 0:
            c += 1
            x /= i
        ans *= (c + 1)
    if not ans:
        ans = 1
    return ans 

def main():
    g = gen()

    maxans = 0
    while True:
        v = g.next()
        u = split(v)
        if u > maxans:
            maxans = u
            print v, u
        if u > 500:
            break

main()

