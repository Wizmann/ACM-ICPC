class Solution(object):
    def fullJustify(self, words, maxWidth):
        lines = self.splitToLines(words, maxWidth)
        n = len(lines)
        return [self.justify(line, i, n, maxWidth) for i, line in enumerate(lines)]
    
    def splitToLines(self, words, maxWidth):
        lines = []
        
        chars, spaces = 0, 0
        cur = []
        for word in words:
            u = len(word) + (1 if cur else 0)
            if chars + spaces + u > maxWidth:
                lines.append(cur)
                chars, spaces, cur = 0, 0, []
            chars += len(word)
            spaces += (1 if cur else 0)
            cur.append(word)
        if cur:
            lines.append(cur)
        return lines
    
    def justify(self, words, cur, n, maxWidth):
        if cur == n - 1 or len(words) == 1:
            res = ' '.join(words)
            res += ' ' * (maxWidth - len(res))
            return res
        
        spaces = maxWidth - sum(map(lambda word: len(word), words))
        
        res = ''
        for i, word in enumerate(words[::-1]):
            deli = spaces if i == len(words) - 1 \
                          else spaces / (len(words) - i - 1)

            res = ' ' * deli + word + res 
            spaces -= deli
        return res
    
    
S = Solution()
assert S.splitToLines(["a", "b", "c"], 1) == [ ["a"], ["b"], ["c"] ]
assert S.splitToLines(["a", "bb", "c"], 2) == [ ["a"], ["bb"], ["c"] ]
assert S.splitToLines(["a", "b", "c"], 3) == [ ["a", "b"], ["c"] ]

assert S.justify(["foo bar"], 1, 2, 10) == "foo bar   "
assert S.justify(["foo", "bar"], 1, 3, 10) == "foo    bar"
assert S.justify(["a", "b", "c"], 1, 4, 6) == "a  b c"

