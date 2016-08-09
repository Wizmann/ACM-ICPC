from utils.prime.primes1m import primes
from utils.prime.func import is_prime


s = set(primes)

def check(a, b):
    ab = int(str(a) + str(b))
    ba = int(str(b) + str(a))
    return is_prime(ab) and is_prime(ba)

primes = primes[:2000]
n = len(primes)

candidates = []
d = {}

for i in xrange(n):
    for j in xrange(i + 1, n):
        a, b = primes[i], primes[j]
        if check(a, b):
            d[a] = d.get(a, [])
            d[b] = d.get(b, [])
            a, b = min(a, b), max(a, b)
            d[a].append(b)

mini = 10 ** 10
ans = []

print len(d)

for key, value in d.items():
    if len(value) < 4:
        continue
    candidates = [key] + value

    m = len(candidates)
    t = []

    def dfs(cur):
        global ans
        global mini

        if cur >= m:
            return

        if sum(t) >= mini:
            return

        cur_i = candidates[cur]
        if t:
            for item in t:
                if not check(cur_i, item):
                    return
        t.append(cur_i)

        if len(t) == 5:
            if sum(t) < mini:
                mini = sum(t)
                ans = t[:]
        else:
            for i in xrange(cur + 1, n):
                dfs(i)
        t.pop()
    dfs(0)
print sum(ans)
