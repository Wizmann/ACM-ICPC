#python3
def solve(st, stops, x, y):
    tt = st + x
    for (p, t) in stops:
        if tt % p:
            tt += p - (tt % p)
        tt += t
    tt += y
    return tt

MAX_T = 840

n, x, y = list(map(int, input().split()))

stops = []

for i in range(n - 1):
    p, t = list(map(int, input().split()))
    stops.append((p, t))

q = int(input())
qs = list(map(int, [input() for i in range(q)]))

res = []
for st in range(MAX_T):
    res.append(solve(st, stops, x, y))

for q in qs:
    base = (q // MAX_T) * MAX_T
    print(base + res[q % MAX_T])

'''
^^^^TEST^^^^
4 2 3
5 4
6 6
3 1
7
13
0
710511029
136397527
763027379
644706927
447672230
---------------
34
22
710511052
136397548
763027402
644706946
447672250
$$$$$TEST$$$$
'''
