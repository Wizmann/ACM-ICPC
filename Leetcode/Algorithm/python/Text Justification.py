class Solution(object):
    def fullJustify(self, words, maxWidth):
        ans = []
        while words:
            line = []
            wordlen = 0
            spaces = 0
            while words:
                cur_length = wordlen + spaces + (1 if line else 0) + len(words[0])
                if cur_length > maxWidth:
                    break
                else:
                    wordlen += len(words[0])
                    spaces += (1 if line else 0)
                    line.append(words[0])
                    del words[0]
            if not words:
                res = " ".join(line)
                ans.append(res + " " * (maxWidth - len(res)))
            elif len(line) == 1:
                ans.append(line[0] + ' ' * (maxWidth - wordlen))
            else:
                spaces = (maxWidth - wordlen)
                res = ''
                for i, word in enumerate(line[::-1]):
                    res = word + res
                    deli = spaces if i == len(line) - 1 else spaces / (len(line) - i - 1)
                    res = ' ' * deli + res
                    spaces -= deli
                ans.append(res)
        return ans
        
