s = raw_input()
st = []
n = len(s)
l = [0 for i in xrange(n)]

maxl, cnt = 0, 1

for i, c in enumerate(s):
    if c == '(':
        st.append(i)
    else:
        if not st:
            continue
        p = st.pop()
        l[i] = (l[p - 1] if p > 0 else 0) + (i - p + 1)
        if l[i] > maxl:
            maxl = l[i]
            cnt = 1
        elif l[i] == maxl:
            cnt += 1

print maxl, cnt
