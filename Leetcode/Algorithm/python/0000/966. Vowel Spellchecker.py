class Solution(object):
    def spellchecker(self, wordlist, queries):
        res = []
        wordlist = wordlist[::-1]
        ws = dict(zip(map(lambda w: w.lower(), wordlist), wordlist))
        wp = dict(zip(map(self.rpVowel, wordlist), wordlist))
        wl = set(wordlist)
         
        for query in queries:
            qa, qb = query.lower(), self.rpVowel(query)
            if query in wl:
                res.append(query)
            elif qa in ws:
                res.append(ws[qa])
            elif qb in wp:
                res.append(wp[qb])
            else:
                res.append('')
        return res
    def rpVowel(self, word):
        res = ''
        word = word.lower()
        for c in word:
            if c in 'aeiou':
                c = '*'
            res += c
        return res
