n = int(raw_input())
ns = map(int, [raw_input() for i in xrange(n)])

ns.append(0)
st = []
ans = 0

for i, num in enumerate(ns):
    while st and num < ns[st[-1]]:
        u = st.pop()
        l = st[-1] + 1 if st else 0
        r = i
        ans = max(ans, (r - l) * ns[u])
    st.append(i)
print ans
