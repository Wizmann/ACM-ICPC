import string

class Solution:
    """
    @param alphabet: the new alphabet
    @param words: the original string array
    @return: the string array after sorting
    """
    def wordSort(self, alphabet, words):
        d = dict(zip(alphabet, string.lowercase))
        return sorted(words, key=lambda word: ''.join(map(lambda c: d[c], word)))
