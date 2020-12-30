class Solution(object):
    def expressiveWords(self, S, words):
        return len(filter(lambda word: self.check(S, word), words))

    def check(self, S, word):
        n, m = len(S), len(word)
        p, q = 0, 0
        while p < n and q < m:
            if S[p] != word[q]:
                return False
            c1, c2 = 0, 0
            cp, cq = S[p], word[q]
            while p < n and S[p] == cp:
                c1 += 1
                p += 1

            while q < m and word[q] == cq:
                c2 += 1
                q += 1

            if c1 == c2:
                continue
            elif c1 > c2 and c1 >= 3:
                continue
            else:
                return False

        return p == n and q == m

assert Solution().check("foo", "foo") == True
assert Solution().check("fooo", "foo") == True
assert Solution().check("foo", "fo") == False
assert Solution().expressiveWords("heeellooo", ["hello", "hi", "helo"]) == 1
