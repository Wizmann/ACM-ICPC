n = int(raw_input())
ns = [raw_input() for i in xrange(n)]
d0, d1 = {}, {}
for item in ns:
    key = ''.join(sorted(item))
    d0[key] = d0.get(key, 0) + 1
for item in ns:
    d1[item] = d1.get(item, 0) + 1

q = int(raw_input())
for i in xrange(q):
    query = raw_input()
    key = ''.join(sorted(query))
    print d0.get(key, 0) - d1.get(query, 0)
