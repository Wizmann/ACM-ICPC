n = int(raw_input())
ns = sorted(map(int, raw_input().split()))

pre = -1
cnt = 0

for num in ns:
    if pre == num: 
        cnt += 1
    else:
        print n - cnt
        n -= cnt
        cnt = 1
        pre = num
