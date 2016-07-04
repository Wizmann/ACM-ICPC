n = int(raw_input())
ns = map(int, raw_input().split())

ans = []

p = 1
for num in ns:
    if not ans:
        ans.append(num)
        continue
    if p == 1 and num >= ans[-1]:
        ans.append(num)
    elif p == -1 and num <= ans[-1]:
        ans.append(num)
    elif p == 1 and num <= ans[-1]:
        ans.append(num)
        ans[-1], ans[-2] = ans[-2], ans[-1]
    elif p == -1 and num >= ans[-1]:
        ans.append(num)
        ans[-1], ans[-2] = ans[-2], ans[-1]
    p *= -1

print ' '.join(map(str, ans))
