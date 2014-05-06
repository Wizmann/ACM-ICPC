n = int(raw_input())
police = 0
ans = 0
for event in map(int, raw_input().split()):
    if event >= 0:
        police += event
    else:
        if police == 0:
            ans += 1
        else:
            police -= 1
print ans
