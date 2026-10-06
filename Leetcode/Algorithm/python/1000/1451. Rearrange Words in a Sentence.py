class Solution(object):
    def arrangeWords(self, text):
        text = sorted(map(lambda (i, t): (len(t), i, t.lower()), enumerate(text.split())))
        res = list(' '.join(map(lambda (l, idx, t): t, text)))
        res[0] = res[0].upper()
        return ''.join(res)
        
        
        
