class Solution(object):
    def pathInZigZagTree(self, label):
        res = []
        l = len('{:b}'.format(label)) - 1
        if l % 2 == 1:
            label = self.convert(label, l)

        while label:
            res.append(label)
            label /= 2
        res = res[::-1]
        for i, v in enumerate(res):
            if i % 2 == 1:
                res[i] = self.convert(res[i], i)
        return res
    
    def convert(self, u, b):
        l = 1 << b
        r = (1 << (b + 1)) - 1
        return l + r - u

