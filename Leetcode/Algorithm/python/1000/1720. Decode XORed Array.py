class Solution(object):
    def decode(self, encoded, first):
        res = [first]
        for num in encoded:
            res.append(res[-1] ^ num)
        return res
