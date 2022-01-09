# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
#class Master(object):
#    def guess(self, word):
#        """
#        :type word: str
#        :rtype int
#        """

import random

def match(a, b):
    ans = 0
    for i in xrange(6):
        if a[i] == b[i]:
            ans += 1
    return ans

class Solution(object):
    def findSecretWord(self, wordlist, master):
        for i in xrange(10):
            w = random.choice(wordlist)
            u = master.guess(w)
            wordlist = filter(lambda word: match(word, w) == u, wordlist)
        
