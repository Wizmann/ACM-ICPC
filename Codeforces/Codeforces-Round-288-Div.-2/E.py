n = int(raw_input())
brackets = [tuple(map(int, raw_input().split())) for i in xrange(n)]

res = ''
ptr = 0

INF = 0xcafebabe
st = []

for (l, r) in brackets:
    res += '('
    st.append((ptr + l, ptr + r))
    ptr += 1
    while st:
        (pre_l, pre_r) = st[-1]
        if pre_l <= ptr <= pre_r:
            res += ')'
            ptr += 1
            st.pop()
        else:
            break

if st:
    print 'IMPOSSIBLE'
else:
    print res
