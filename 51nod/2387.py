(n, c, d) = map(int, raw_input().split())
ns = sorted(map(int, raw_input().split()), reverse=True)

c = (c - d) + 2 * d

cnt = 0
while c and ns:
    if ns[-1] <= c:
        c -= ns[-1]
        cnt += 1
        ns.pop()
    else:
        break
print cnt
