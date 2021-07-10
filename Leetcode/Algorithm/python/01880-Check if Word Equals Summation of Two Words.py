class Solution(object):
    def isSumEqual(self, firstWord, secondWord, targetWord):
        convert = lambda c : str(ord(c) - ord('a'))
        a = map(int, ''.join(map(convert, firstWord)))
        b = map(int, ''.join(map(convert, secondWord)))
        c = map(int, ''.join(map(convert, targetWord)))
        # print a, b, c
        return a + b == c
