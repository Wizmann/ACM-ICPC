def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

N = 12345
sieve = [True for i in xrange(N)]

i = 2
while i * i < N:
    if sieve[i]:
        j = 2
        while i * j < N:
            sieve[i * j] = False
            j += 1
    i += 1

primes = []
for i in xrange(2, N):
    if sieve[i]:
        primes.append(i)

MAXI = 10000

pack = [6, 10, 15]

def solve(n):
    res = set(pack[:])

    for num in pack:
        for i in xrange(2, N):
            if len(res) < n and num * i <= MAXI:
                if num * i in res:
                    continue
                res.add(num * i)
            else:
                break

    # print res

    '''
    for i in xrange(n):
        for j in xrange(i + 1, n):
            assert gcd(res[i], res[j]) != 1
    assert len(res) == n
    assert len(set(res)) == len(res)
    assert reduce(gcd, res) == 1
    assert min(res) >= 1
    assert max(res) <= 10000
    '''

    return list(res)

'''
for i in xrange(3, 2500 + 1):
    print i
    solve(i)
'''

n = int(raw_input())

res = solve(n)

print ' '.join(map(str, res))


'''
^^^TEST^^^
4
-----
84 60 105 70
$$$TEST$$$

^^^TEST^^^
1000
-----
84 60 105 70
$$$TEST$$$
'''
