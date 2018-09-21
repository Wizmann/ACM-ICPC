def to_base3(u):
    res = ''
    while u:
        res = str(u % 3) + res
        u /= 3
    return res

res = [9]
for i in xrange(1, 3 ** 10):
    u = int(to_base3(i))
    if str(u) == str(u)[::-1] and str(u * u) == str(u * u)[::-1]:
        res.append(u * u)
    res.sort()

class Solution(object):
    def superpalindromesInRange(self, L, R):
        return len(filter(lambda x: x <= int(R), res)) - len(filter(lambda x: x < int(L), res))
