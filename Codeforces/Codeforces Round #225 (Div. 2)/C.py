n = int(raw_input())
cows = map(int, raw_input().split())
cnt = 0
res = 0
for cow in cows:
    cnt += cow
    if not cow:
        res += cnt
print res
