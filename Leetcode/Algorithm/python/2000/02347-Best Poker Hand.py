from collections import Counter

class Solution(object):
    def bestHand(self, ranks, suits):
        if len(set(suits)) == 1:
            return "Flush"
        c = Counter(ranks)
        if max(c.values()) >= 3:
            return "Three of a Kind"
        elif max(c.values()) >= 2:
            return "Pair"
        else:
            return "High Card"
