from collections import defaultdict

class Solution(object):
    def beautifulSubstrings(self, s, k):
        mods = []
        for i in xrange(k + 1):
            if (i * i) % k == 0:
                mods.append(i)

        d = defaultdict(int)
        d2 = defaultdict(int)
        res = 0
        v, c = 0, 0
        # diff, cnt_mod
        d[(0, 0)] = 1
        d2[0] = 1
        for ch in s:
            if ch in 'aeiou':
                v += 1
            else:
                c += 1

            if (v - c) in d2 and min(v, c) ** 2 >= k:
                visited = set()
                for mod in mods:
                    i = ((min(v, c) % k - mod) % k + k) % k
                    if i in visited:
                        continue
                    visited.add(i)
                    diff = v - c
                    # print ch, diff, i, d[(diff, i)]
                    res += d[(diff, i)]

            d[v - c, min(v, c) % k] += 1
            d2[v - c] += 1
        return res

assert Solution().beautifulSubstrings('baeyh', 2) == 2
assert Solution().beautifulSubstrings('abba', 1) == 3
