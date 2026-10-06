class Solution(object):
    def replaceWords(self, dict, sentence):
        res = []
        dict.sort(key=lambda word: len(word))
        for item in sentence.split():
            res.append(self.rep(dict, item))
        
        return ' '.join(res)
    
    def rep(self, dict, item):
        for word in dict:
            if item.startswith(word):
                return word
        return item
