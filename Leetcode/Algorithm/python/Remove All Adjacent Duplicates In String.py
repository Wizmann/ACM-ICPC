class Solution(object):
    def removeDuplicates(self, S):
        T = []
        for c in S:
            if T and T[-1] == c:
                T.pop()
                continue
            T.append(c)
        return ''.join(T)
