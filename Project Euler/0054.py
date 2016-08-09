import sys
class Card(object):
    def __init__(self, value, suit):
        self.value = value
        self.suit = suit

class IRule(object):
    rank = -1
    def process(self, cards):
        return [self.rank] + self.do_process(cards) + sorted(map(lambda x: x.value, cards), reverse=True)
    def do_process(self, cards):
        raise NotImplementedError

class HighCard(IRule):
    def do_process(self, cards):
        cards = map(lambda x: x.value, cards)
        return [1, max(cards)]

class OnePair(IRule):
    def do_process(self, cards):
        d = {}
        cards = map(lambda x: x.value, cards)
        for card in cards:
            d[card] = d.get(card, 0) + 1
        res = -1
        for key, value in d.items():
            if value == 2:
                res = max(res, key)
        if res == -1:
            return [0, -1]
        else:
            return [1, res]

class TwoPairs(IRule):
    def do_process(self, cards):
        d = {}
        cards = map(lambda x: x.value, cards)
        for card in cards:
            d[card] = d.get(card, 0) + 1
        res = []
        for key, value in d.items():
            if value == 2:
                res.append(key)

        if len(res) != 2:
            return [0, -1]
        else:
            return [1, max(res)]

class ThreeOfAKind(IRule):
    def do_process(self, cards):
        d = {}
        cards = map(lambda x: x.value, cards)
        for card in cards:
            d[card] = d.get(card, 0) + 1
        res = -1
        for key, value in d.items():
            if value == 3:
                res = max(res, key)
        if res == -1:
            return [0, -1]
        else:
            return [1, res]

class Straight(IRule):
    def do_process(self, cards):
        cards = map(lambda x: x.value, cards)
        cards.sort()
        if len(set(cards)) == len(cards) and cards[-1] - cards[0] + 1 == len(cards):
            return [1, max(cards)]
        else:
            return [0, -1]

class Flush(IRule):
    def do_process(self, cards):
        suits = set(map(lambda x: x.suit, cards))
        cards = map(lambda x: x.value, cards)
        if len(suits) == 1:
            return [1, max(cards)]
        else:
            return [0, -1]

class FullHouse(IRule):
    def do_process(self, cards):
        cards = map(lambda x: x.value, cards)
        d = {}
        for card in cards:
            d[card] = d.get(card, 0) + 1
        d = sorted(d.items(), key=lambda x: x[1])
        if d[0][1] == 2 and d[1][1] == 3:
            return [1, d[1][0]]
        else:
            return [0, -1]

class FourOfAKind(IRule):
    def do_process(self, cards):
        d = {}
        cards = map(lambda x: x.value, cards)
        for card in cards:
            d[card] = d.get(card, 0) + 1
        res = -1
        for key, value in d.items():
            if value == 4:
                res = max(res, key)
        if res == -1:
            return [0, -1]
        else:
            return [1, res]

class StraightFlush(IRule):
    def do_process(self, cards):
        ra = Flush()
        rb = Straight()
        if ra.do_process(cards)[0] and rb.do_process(cards)[0]:
            cards = map(lambda x: x.value, cards)
            return [1, max(cards)]
        else:
            return [0, -1]

class RoyalFlush(IRule):
    def do_process(self, cards):
        cards = sorted(map(lambda x: x.value, cards))
        if cards == [10, 11, 12, 13, 14]:
            return [1, 14]
        else:
            return [0, -1]

rules = [
    HighCard(), 
    OnePair(), 
    TwoPairs(), 
    ThreeOfAKind(), 
    Straight(), 
    Flush(), 
    FullHouse(), 
    FourOfAKind(), 
    StraightFlush(), 
    RoyalFlush()
]
for i, rule in enumerate(rules):
    rules[i].rank = i

rules = rules[::-1]

valueD = {
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    'T': 10,
    'J': 11,
    'Q': 12,
    'K': 13,
    'A': 14
}

def evaluation(cards):
    res = filter(lambda x: x[1], map(lambda x: x.process(cards), rules))
    return max(res)

def parse_card(card):
    value, suit = card[:-1], card[-1]
    return Card(valueD[value], suit)

def parse_cards(line):
    return map(parse_card, line.split())

def solve(line):
    if not line.strip():
        return 0
    cards = line.split()
    c1, c2 = map(parse_card, cards[:5]), map(parse_card, cards[5:])
    e1, e2 = evaluation(c1), evaluation(c2)
    return e1 > e2

def test():
    assert(solve("5H 5C 6S 7S KD 2C 3S 8S 8D TD") == False)
    assert(solve("5D 8C 9S JS AC 2C 5C 7D 8S QH") == True)
    assert(solve("2D 9C AS AH AC 3D 6D 7D TD QD") == False)
    assert(solve("4D 6S 9H QH QC 3D 6D 7H QD QS") == True)
    assert(solve("2H 2D 4C 4D 4S 3C 3D 3S 9S 9D") == True)

    rf = RoyalFlush()
    assert(rf.do_process(parse_cards("TA JB QC KD AE"))[0] == 1)

    fk = FourOfAKind()
    assert(fk.do_process(parse_cards("TA TB QC TD TE"))[0] == 1)

    hc = HighCard()
    hc1 = hc.process(parse_cards("AX 2X 2X 3X 4X"))
    hc2 = hc.process(parse_cards("AX 2X 2X 2X 4X"))
    assert(hc1 > hc2)

test()

if __name__ == '__main__':
    res = 0
    for line in sys.stdin:
        res += solve(line)
    print res
