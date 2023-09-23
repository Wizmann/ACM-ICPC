#python3

def check(ns, width, maxline):
    w = 0
    line = 0
    for num in ns:
        nxt = w
        if w == 0:
            nxt += num
        else:
            nxt += num + 1
        # print w, nxt, width

        if nxt == width:
            w = 0
            line += 1
        elif nxt > width:
            line += 1
            w = num
        else:
            w = nxt
            assert(w <= width)

        if line > maxline:
            return False
    if w:
        line += 1
    return line <= maxline


n, m = list(map(int, input().split()))
ns = list(map(int, input().split()))

l, r = max(ns), 2 ** 64

# print check(ns, 18, m)
while l <= r:
    mid = (l + r) // 2
    if check(ns, mid, m):
        r = mid - 1
    else:
        l = mid + 1

print(l)

'''
^^^^TEST^^^^
13 3
9 5 2 7 1 8 8 2 1 5 2 3 6
-----------
26
$$$TEST$$$

^^^^TEST^^^^
10 1
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
-----------
10000000009
$$$TEST$$$

^^^^TEST^^^^
30 8
8 55 26 97 48 37 47 35 55 5 17 62 2 60 23 99 73 34 75 7 46 82 84 29 41 32 31 52 32 60
-----------
189
$$$TEST$$$

'''
