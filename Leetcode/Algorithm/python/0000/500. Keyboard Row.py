import re

class Solution(object):
    def findWords(self, words):
        return filter(lambda x: re.search('^([qwertyuiop]+|[asdfghjkl]+|[zxcvbnm]+)$', x.lower()), words)
