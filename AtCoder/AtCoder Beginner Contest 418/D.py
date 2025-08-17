#python3

def get_res(S, nxt):
    cur = 0
    res = []
    while cur != -1:
        c = S[cur]
        cur = nxt[cur]
        res.append(c)
    return res

xrange = range
raw_input = input

n, m = list(map(int, raw_input().split()))
s = raw_input()
t = raw_input()

S = '#' + s + '#' + t
N = len(S)
nxt = [-1 for i in xrange(N)]

for i in xrange(0, n):
    nxt[i] = i + 1

# #foo#bar

for i in xrange(n + 1, N - 1):
    nxt[i] = i + 1

assert(N == 2 * n + 2)
assert(nxt[n] == -1)
assert(nxt[-1] == -1)

for i in xrange(m):
    a, b = list(map(int, raw_input().split()))
    pre_1 = a - 1
    pre_2 = n + a
    # print(pre_1, pre_2)
    nxt_1 = b
    nxt_2 = n + b + 1
    # print(nxt_1, nxt_2)

    nxt[pre_1], nxt[pre_2] = nxt[pre_2], nxt[pre_1]
    nxt[nxt_1], nxt[nxt_2] = nxt[nxt_2], nxt[nxt_1]
    # res = get_res(S, nxt)
    # print(res)

res = get_res(S, nxt)

print(''.join(res[1:]))
    

'''
^^^^TEST^^^^
5 3
apple
lemon
2 4
1 5
5 5
-----------
lpple
$$$$$TEST$$$$


^^^^TEST^^^^
10 5
lemwrbogje
omsjbfggme
5 8
4 8
1 3
6 6
1 4
-----------
lemwrfogje
$$$$$TEST$$$$

'''
