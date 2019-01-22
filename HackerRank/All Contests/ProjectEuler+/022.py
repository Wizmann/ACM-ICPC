def get_score(i, s):
    res = 0
    for c in s:
        res += ord(c) - ord('A') + 1
    res *= i
    return res

n = int(raw_input())

d = {}

names = sorted([raw_input() for i in xrange(n)])

for i, name in enumerate(names):
    d[name] = get_score(i + 1, name)
    
q = int(raw_input())

for i in xrange(q):
    name = raw_input()
    print d[name]
