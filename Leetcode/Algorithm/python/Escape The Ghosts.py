INF = 10 ** 10

class Solution(object):
    def escapeGhosts(self, ghosts, target):
        u = abs(target[0]) + abs(target[1])
        v = INF
        for ghost in ghosts:
            v = min(v, abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]))
        return u < v
