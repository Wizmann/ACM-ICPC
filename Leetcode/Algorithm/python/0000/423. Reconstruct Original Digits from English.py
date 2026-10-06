from collections import Counter

class Solution(object):
    def originalDigits(self, s):
        digits = [
            ('z', 'zero', 0),
            ('w', 'two', 2),
            ('x', 'six', 6),
            ('s', 'seven', 7),
            ('v', 'five', 5),
            ('f', 'four', 4),
            ('o', 'one', 1),
            ('g', 'eight', 8),
            ('i', 'nine', 9),
            ('t', 'three', 3),
        ]
        
        s = Counter(list(s))
        print s
        ans = ''
        for digit in digits:
            (c, word, num) = digit
            cnt = s[c]
            ans += str(num) * cnt
            
            for c in word:
                s[c] -= cnt
        return ''.join(sorted(ans))
            
