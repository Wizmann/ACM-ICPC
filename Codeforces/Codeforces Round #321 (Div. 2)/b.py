(n, d) = map(int, raw_input().split())

friends = [
    tuple(map(int, raw_input().split()))
    for i in xrange(n)
]

friends.sort(key=lambda x: x[0])

ans = 0
peak = 0
s = 0

for i, friend in enumerate(friends):
    while peak < i and abs(friends[peak][0] - friend[0]) >= d:
        s -= friends[peak][1]
        peak += 1
    s += friend[1]        
    ans = max(ans, s)

print ans

