class Solution(object):
    def miceAndCheese(self, reward1, reward2, k):
        n = len(reward1)
        tot = sum(reward1)
        for i in xrange(n):
            reward1[i] = reward2[i] - reward1[i]
        reward1.sort(reverse=True)
        # print reward1
        delta = sum(reward1[:n - k])
        return tot + delta
