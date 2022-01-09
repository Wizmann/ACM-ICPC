class Solution(object):
    def reverseOnlyLetters(self, S):
        S = list(S)
        T = filter(lambda c: c.isalpha(), S)[::-1]
        for i, c in enumerate(S):
            if c.isalpha():
                S[i] = T.pop(0)
        return ''.join(S)
