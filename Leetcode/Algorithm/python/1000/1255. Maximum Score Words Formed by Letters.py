from collections import Counter

class Solution(object):
    def maxScoreWords(self, words, letters, score):
        c = Counter(letters)
        n = len(words)
        scores = []
        
        for word in words:
            w = Counter(word)
            s = 0
            for (key, value) in w.items():
                key = ord(key) - ord('a')
                s += score[key] * value
            scores.append(s)
            
        res = 0
        for i in xrange(1 << n):
            word = ''
            maxi = 0
            for j in xrange(n):
                if i & (1 << j):
                    word += words[j]
                    maxi += scores[j]
            if maxi <= res:
                continue
                
            w = Counter(word)
            flag = True
            for (key, value) in w.items():
                if c.get(key, 0) < value:
                    flag = False
                    break
            if flag:
                res = max(res, maxi)
        return res
