n, a, b = map(int, raw_input().split())
ts = map(int, raw_input().split())

for t in ts:
    c = (t * a) % b
    print c / a,
