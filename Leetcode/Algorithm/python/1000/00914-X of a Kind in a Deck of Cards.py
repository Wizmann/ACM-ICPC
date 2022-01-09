from collections import Counter

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

class Solution(object):
    def hasGroupsSizeX(self, deck):
        return reduce(lambda x, y: gcd(x, y), Counter(deck).values()) >= 2
        
