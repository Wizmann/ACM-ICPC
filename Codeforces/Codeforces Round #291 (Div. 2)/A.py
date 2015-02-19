ns = map(int, list(raw_input()))

for i, n in enumerate(ns):
    if 5 <= n <= 8 or (i != 0 and n == 9):
        ns[i] = 9 - n

print ''.join(map(str, ns))
