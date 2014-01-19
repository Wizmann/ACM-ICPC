def fsum(x):
    x = str(x)
    return sum(map(lambda v: reduce(lambda a, b: a * b, range(1, v + 1), 1), map(int, x)))

def upper():
    l = 1
    while True:
        a = int('9' * l)
        if fsum(a) < a:
            return a
        l += 1

u = upper()

ans = 0
for i in xrange(3, u):
    if fsum(i) == i:
        print i
        ans += i
print ans
