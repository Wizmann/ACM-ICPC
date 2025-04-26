class Solution(object):
    def areAlmostEqual(self, s1, s2):
        if s1 == s2:
            return True
        if len(s1) != len(s2):
            return False
        ps = []
        for (a, b) in zip(s1, s2):
            if a != b:
                ps.append((a, b))
        if len(ps) == 2 and ps[0] == ps[1][::-1]:
            return True
        return False
