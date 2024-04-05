INF = 10 ** 10

n, k = map(int, raw_input().split())
ns = map(int, raw_input().split())

st = []

for i in xrange(n):
    while st and i - st[0] >= k:
        st.pop(0)
    while st and ns[i] > ns[st[-1]]:
        st.pop()
    st.append(i)
    if i >= k - 1:
        print ns[st[0]]
