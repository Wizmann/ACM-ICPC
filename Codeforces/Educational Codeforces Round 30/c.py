(n, m, k) = map(int, raw_input().split())
ns = [ map(int, raw_input().split()) for i in xrange(n) ]

for j in xrange(m):
    for i in xrange(1, n):
        ns[i][j] += ns[i - 1][j]

score, rep = 0, 0

for j in xrange(m):
    mscore, mrep = 0, 0

    for i in xrange(n):
        upper = 0 if i - 1 < 0 else ns[i - 1][j]
        lower = ns[min(n - 1, i + k - 1)][j] - (0 if i - 1 < 0 else ns[i - 1][j])

        if lower > mscore:
            mscore, mrep = lower, upper
        elif lower == mscore:
            mrep = min(mrep, upper)

    score, rep = score + mscore, rep + mrep

print score, rep
