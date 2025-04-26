def product(a, b):
    res = []
    for item_a in a:
        for item_b in b:
            res.append(item_a + item_b)
    return res

class Solution(object):
    def letterCasePermutation(self, S):
        S = [[c.upper(), c.lower()] if c.isalpha() else [c] for c in S]
        return reduce(product, S, [''])
