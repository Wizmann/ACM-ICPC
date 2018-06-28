INF = 10 ** 10

n = int(raw_input())
ns = map(int, raw_input().split())

st = []
mini, maxi = INF, -INF
for num in ns:
    while st and st[-1] > num:
        u = st.pop()
        mini = min(mini, u, num)
        maxi = max(maxi, u, num)
    st.append(num)
print len(filter(lambda u: mini <= u <= maxi, ns))
