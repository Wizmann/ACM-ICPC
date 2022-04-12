n = int(raw_input())
st = []

head = 0
for i in xrange(n):
    cmd = map(int, raw_input().split())
    # print st
    if cmd[0] == 1:
        _, x, c = cmd
        st.append([x, c])
    elif cmd[0] == 2:
        _, query = cmd
        res = 0
        while query:
            assert st and head < len(st)
            x, c = st[head]
            if query >= c:
                query -= c
                res += x * c
                head += 1
            else:
                res += x * query
                st[head][1] -= query
                query = 0
        print res
    else:
        assert False

'''
^^^TEST^^^
4
1 2 3
2 2
1 3 4
2 3
------
4
8
$$$TEST$$$

^^^^TEST^^^
2
1 1000000000 1000000000
2 1000000000
--------
1000000000000000000
$$$TEST$$$
'''


