import string

INF = 10 ** 100

class Solution(object):
    def minimizeConcatenatedLength(self, words):
        dp = {}

        for i, word in enumerate(words):
            if i == 0:
                dp[word[0] + word[-1]] = len(word)
                continue

            dp2 = {}

            for key, value in dp.items():
                dp2[key[0] + word[-1]] = min(
                    dp2.get(key[0] + word[-1], INF),
                    value + len(word) - (key[-1] == word[0]))

                dp2[word[0] + key[-1]] = min(
                    dp2.get(word[0] + key[-1], INF),
                    value + len(word) - (key[0] == word[-1]))
            dp = dp2
        return min(dp.values())

'''
^^^^^^TEST^^^^^^^
["aa","ab","bc"]
-------------
4
$$$$$$$$TEST$$$$$

^^^^^^TEST^^^^^^^
["ab","b"]
-------------
2
$$$$$$$$TEST$$$$$

^^^^^^TEST^^^^^^^
["aaa","c","aba"]
-------------
6
$$$$$$$$TEST$$$$$

^^^^^^TEST^^^^^^^
["vmrf","bo","pvgghuyq","lvltw","suuny","e","ed","af","kuv","q","jexvdn","gn","sxwei","yp","czrg","rg","rx","gbc","awfrqmjvkt","pcmwihlrih","nywbpnbkk","khh","lpfkaxx","fma","ajzvu","rsdeww","nrhkxr","sahnfrday","wshc","jpcn","feggbqsc","tvdj","v","octsgrqd","nxxqpe","e","a","ymr","d","bvcudgcv","cwsjc","nsbhixpt","zkyp","rmm","lcvbhbdd","gqiesajona","engb","uwsbaozvgw","hkanmoqkvq","nua","korgcs","dltngfhgae","zwevophd","zeckn","vmajvx","rxfwiym","kk","lpddjdjddk","bnbplmbv","durzwo","orwouq"]
-------------
299
$$$$$$$$TEST$$$$$
'''
