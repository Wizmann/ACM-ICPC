(n, d) = map(int, raw_input().split())
ts = map(int, raw_input().split())

min_time = sum(ts) + 10 * (len(ts) - 1)

if min_time > d:
    print -1
else:
    print (len(ts) - 1) * 2 + (d - min_time) / 5
