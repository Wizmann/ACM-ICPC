class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        cnt = 0
        for word in text.split():
            if set(word) & set(brokenLetters):
                continue
            cnt += 1
        return cnt
                
