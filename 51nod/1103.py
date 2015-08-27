n = int(raw_input())
ns = map(int, [raw_input() for i in xrange(n)])
mods = map(lambda x: x % n, ns)

d = {0: -1}
mod_sum = 0
for i, mod in enumerate(mods):
    mod_sum = (mod_sum + mod) % n
    if mod_sum in d:
        l = d[mod_sum] + 1
        r = i
        print r - l + 1
        print '\n'.join(map(str, ns[l:r + 1]))
        break
    d[mod_sum] = i
