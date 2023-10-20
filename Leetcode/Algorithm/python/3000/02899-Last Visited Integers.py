class Solution(object):
    def lastVisitedIntegers(self, words):
        res = []
        ns = []
        cnt = 0
        for word in words:
            if word.isdigit():
                ns.append(int(word))
                cnt = 0
            else:
                cnt += 1
                # print ns, cnt
                if cnt <= len(ns):
                    res.append(ns[-cnt])
                else:
                    res.append(-1)
        return res
