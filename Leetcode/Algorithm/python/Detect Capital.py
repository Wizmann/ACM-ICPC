class Solution(object):
    def detectCapitalUse(self, word):
        if not word:
            return False
        if all(map(lambda c: c.isupper(), word)):
            return True
        if all(map(lambda c: c.islower(), word)):
            return True
        if word[0].isupper() and all(map(lambda c: c.islower(), word[1:])):
            return True
            
        return False

S = Solution()

assert(S.detectCapitalUse("USA") == True)
assert(S.detectCapitalUse("leetcode") == True)
assert(S.detectCapitalUse("FlaG") == False)

assert(S.detectCapitalUse("") == False)
assert(S.detectCapitalUse("213") == False)
assert(S.detectCapitalUse("abd") == True)
assert(S.detectCapitalUse("zzz") == True)
assert(S.detectCapitalUse("!!!") == False)
assert(S.detectCapitalUse(" ") == False)
assert(S.detectCapitalUse("\n") == False)


assert(S.detectCapitalUse("A") == True)
assert(S.detectCapitalUse("ZZZ") == True)
assert(S.detectCapitalUse("ZZZ123") == False)
assert(S.detectCapitalUse("ZZZzzz") == False)
assert(S.detectCapitalUse("ZZZ!!!") == False)
