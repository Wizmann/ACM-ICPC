class Solution(object):
    def validSequence(self, word1, word2):
        n, m = len(word1), len(word2)
        p, q = n - 1, m - 1
        dp1 = [0 for i in xrange(n + 1)]
        cnt1 = 0
        while p >= 0:
            if q >= 0 and word1[p] == word2[q]:
                cnt1 += 1
                q -= 1
            dp1[p] = cnt1
            p -= 1
        cnt2 = 0
        p, q = 0, 0
        res = []
        flag = False
        while p < n and q < m:
            while p < n and q < m and word1[p] == word2[q]:
                cnt2 += 1
                res.append(p)
                q += 1
                p += 1
                
            if dp1[p + 1] + q + 1 >= m:
                res.append(p)
                p += 1
                q += 1
                flag = True
                break
            p += 1

        if flag:
            while p < n and q < m:
                if word1[p] == word2[q]:
                    res.append(p)
                    p += 1
                    q += 1
                else:
                    p += 1
            return res
        else:
            return []
            
assert Solution().validSequence("cbcbccbbcbcbbbb", "bb") == [0, 1]
assert Solution().validSequence("ccccccc", "c") == [0]
assert Solution().validSequence("vbcca", "abc") == [0, 1, 2]
