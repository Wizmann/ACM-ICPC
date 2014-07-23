(p, n) = map(int, raw_input().split())
st = set()
conflict = -1
for i in xrange(n):
    v = int(raw_input()) % p
    if v in st:
        conflict = i + 1 # <= TEST
        break
    else:
        st.add(v)
print conflict
