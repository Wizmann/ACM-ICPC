import string
ns = sorted(map(list, filter(lambda x: x[0], zip(map(int, raw_input().split()), string.lowercase))))

res = ns[0][1]
ns[0][0] -= 1
if ns[0][0] == 0:
    del ns[0]

ns = sorted(ns, key = lambda x: x[1])

while ns:
    ptr = 0
    if len(res) >= 2 and len(ns) >= 2 and res[0] == res[1] == res[-1] == ns[0][1]:
        ptr = 1
    res += ns[ptr][1]
    ns[ptr][0] -= 1
    if ns[ptr][0] == 0:
        del ns[ptr]
print res
