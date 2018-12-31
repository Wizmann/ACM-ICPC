def bruteforce(n):
    s = set()
    for i in xrange(1, n + 1):
        cur = 0
        tot = 0
        while True:
            tot += cur + 1
            cur = (cur + i) % n
            if cur == 0:
                break
        s.add(tot)
    return s

def do_solve(m, n):
    step = n / m
    return (1 + (step - 1) * m + 1) * step / 2

def solve(n):
    i = 1
    s = set()
    while i * i <= n:
        if n % i == 0:
            a, b = i, n / i
            s.add(do_solve(a, n))
            s.add(do_solve(b, n))
        i += 1
    return s

n = int(raw_input())
for num in sorted(solve(n)):
    print num,
print ''
