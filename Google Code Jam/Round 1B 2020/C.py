# https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b64

input = raw_input

MOD = 0xdeadbeefdeadbeef
INF = 10 ** 10
PRIME = 53

def hash(cards):
    res = 0
    for card in cards:
        res = ((res * PRIME) + card) % MOD
    return res

class Solution(object):
    def __init__(self):
        pass

    def solve(self, r, s):
        self.r = r
        self.s = s
        cards = []
        for j in xrange(s):
            for i in xrange(r):
                cards.append(i + 1)
                

        rem = len(cards) - 1
        n = len(cards)
        res = []
        while rem > self.r:
            lenA = self.find(cards, 0, lambda x: x != cards[0])
            lenB = self.find(cards, lenA, lambda x: x == cards[0])
            res.append((lenA, lenB))
            cards = cards[lenA: lenA + lenB] + cards[:lenA] + cards[lenA + lenB:]
            rem -= 2

        if rem - (self.r - 1) == 1:
            res.append((s - 1, len(cards) - (s - 1)))

        return res

    def find(self, cards, start, check):
        for i in xrange(start, len(cards)):
            if check(cards[i]):
                break
        for j in xrange(i, len(cards)):
            if cards[j] != cards[i]:
                break
        return j - start


# print Solution().solve(2, 2)

T = int(input())
for case_ in xrange(T):
    (r, s) = map(int, input().split())

    res = Solution().solve(r, s)

    print "Case #%d: %d" % (case_ + 1, len(res))
    for (a, b) in res:
        print a, b
