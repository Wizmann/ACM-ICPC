class Solution(object):
    def decodeAtIndex(self, S, K):
        K -= 1
        return self._decodeAtIndex(S, K)

    def _decodeAtIndex(self, S, K):
        tape = 0
        for i, c in enumerate(S):
            if c.isdigit():
                c = int(c)
                if tape * c <= K:
                    tape *= c
                else:
                    K %= tape
                    return self._decodeAtIndex(S[:i], K)
            else:
                if tape == K:
                    return c
                tape += 1

assert Solution().decodeAtIndex('a2b3c4d5e6f7g8h9', 3) == 'b'
assert Solution().decodeAtIndex('leet2code3', 10) == 'o'
assert Solution().decodeAtIndex('ha22', 5) == 'h'
assert Solution().decodeAtIndex('a2345678999999999999999', 1) == 'a'
assert Solution().decodeAtIndex('a2345678999999999999999', 123) == 'a'

