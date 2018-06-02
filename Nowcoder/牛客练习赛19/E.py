n = int(raw_input())
st = set()
bottles = [0 for i in xrange(n)]
for i in xrange(n):
    (a, b) = map(int, raw_input().split())
    st.add((i, b))
    bottles[i] = a
     
res = set()
for i in xrange(n):
    for j in xrange(n):
        x, y = bottles[i], bottles[j]
        if i == j:
            continue
        if (i, y) in st:
            res.add(j)
print n - len(res)