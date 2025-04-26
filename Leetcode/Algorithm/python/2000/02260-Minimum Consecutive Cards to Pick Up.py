INF = 10 ** 10

class Solution(object):
    def minimumCardPickup(self, cards):
        res = INF
        d = {}
        for i, card in enumerate(cards):
            if card in d:
                res = min(res, i - d[card] + 1)
            d[card] = i
        if res >= INF:
            res = -1
        return res
