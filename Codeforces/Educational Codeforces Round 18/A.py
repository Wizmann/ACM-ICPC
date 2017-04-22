n = int(raw_input())
ns = sorted(map(int, raw_input().split()))

mini = 10 ** 10
cnt = 0

for i in xrange(1, n):
    dis = ns[i] - ns[i - 1]
    if dis < mini:
        mini, cnt = dis, 1
    elif dis == mini:
        cnt += 1
print mini, cnt
