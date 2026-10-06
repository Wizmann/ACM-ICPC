class Solution(object):
    def isSumEqual(self, firstWord, secondWord, targetWord):
        convert = lambda c : str(ord(c) - ord('a'))
        a = map(int, ''.join(map(convert, firstWord)))
        b = map(int, ''.join(map(convert, secondWord)))
        c = map(int, ''.join(map(convert, targetWord)))
        a, b, c = map(lambda x: int(''.join(map(str, x))), [a, b, c])
        return a + b == c
