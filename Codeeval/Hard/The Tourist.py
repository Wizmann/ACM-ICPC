import sys

# sys.stdin = open(sys.argv[1], 'r')

sys.stdin = open('input.txt')

for line in sys.stdin:
    d = {}
    idx = 0
    maxi = 0
    roads = {}

    for road in line.split('|'):
        (a, b, c) = map(int, road.split())
        
        maxi = max(maxi, a, b)
        
        if a not in d:
            d[a] = idx
            idx += 1

        if b not in d:
            d[b] = idx
            idx +=  1

        a, b = d[a], d[b]

        roads[(a, b)] = c
        roads[(b, a)] = c
    
    roads = [(a, b, c) for ((a, b), c) in roads.items()]
    roads.sort(key=lambda x: x[2])

    father = [i for i in xrange(idx)]

    def find_father(x):
        if x == father[x]:
            return x
        else:
            father[x] = find_father(father[x])
            return father[x]

    ans = 0
    for road in roads:
        (a, b, c) = road
        if find_father(a) != find_father(b):
            ans += c
            father[find_father(a)] = find_father(b)
            
    flag = (maxi == idx)
    
    for i in xrange(idx):
        for j in xrange(i + 1, idx):
            if find_father(i) != find_father(j):
                flag = False
    if not flag:
        print 'False'
    else:
        print ans
